/*******************************************************************************
 Copyright (C) 2010  Bryan Godbolt godbolt ( a t ) ualberta.ca

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.

 ****************************************************************************/

#include <iostream>

#include <GroundControlStation.h>

uint64_t microsSinceEpoch();

GroundControlStation::GroundControlStation(QObject *parent) :
    QObject(parent)
{
    m_flyingObjectLatitude = 0.0;
    m_flyingObjectLongitude = 0.0;
    m_flyingObjectAltitude = 0.0;

    configureMAVLink();

    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, this, &GroundControlStation::UpdateData);
    m_timer->start(250);
}

void GroundControlStation::configureMAVLink() {
    m_sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
    m_fromlen = sizeof(m_gcAddr);
    m_i = 0;
    m_temp = 0;

    strcpy(m_target_ip, "127.0.0.1");

    memset(&m_locAddr, 0, sizeof(m_locAddr));
    m_locAddr.sin_family = AF_INET;
    m_locAddr.sin_addr.s_addr = INADDR_ANY;
    m_locAddr.sin_port = htons(14550);

    if (-1 == bind(m_sock,(struct sockaddr *)&m_locAddr, sizeof(struct sockaddr)))
    {
        perror("error bind failed");
        close(m_sock);
        exit(EXIT_FAILURE);
    }

    /* Attempt to make it non blocking */
#if (defined __QNX__) | (defined __QNXNTO__)
    if (fcntl(sock, F_SETFL, O_NONBLOCK | FASYNC) < 0)
#else
    if (fcntl(m_sock, F_SETFL, O_NONBLOCK | O_ASYNC) < 0)
#endif

    {
        fprintf(stderr, "error setting nonblocking: %s\n", strerror(errno));
        close(m_sock);
        exit(EXIT_FAILURE);
    }

    memset(&m_gcAddr, 0, sizeof(m_gcAddr));
    m_gcAddr.sin_family = AF_INET;
    m_gcAddr.sin_addr.s_addr = inet_addr(m_target_ip);
    m_gcAddr.sin_port = htons(14551);
}

void GroundControlStation::UpdateData() {
    uint8_t buf[BUFFER_LENGTH];
    int i(0);

    memset(buf, 0, BUFFER_LENGTH);
    m_recsize = recvfrom(m_sock, (void *)buf, BUFFER_LENGTH, 0, (struct sockaddr *)&m_gcAddr, &m_fromlen);
    if (m_recsize > 0)
    {
        // Something received - print out all bytes and parse packet
        mavlink_message_t msg;
        mavlink_status_t status;

        //std::cout << "Bytes Received: " << (int)m_recsize << std::endl << "Datagram: ";
        for (i = 0; i < m_recsize; ++i)
        {
            m_temp = buf[i];
            //printf("%02x ", (unsigned char)m_temp);
            if (mavlink_parse_char(MAVLINK_COMM_0, buf[i], &msg, &status))
            {
                if (msg.msgid == MAVLINK_MSG_ID_LOCAL_POSITION_NED) {
                    //struct LOCAL_POSITION_NED local_position;
                    //std::cout << std::endl << "--- POSITION ---" << std::endl;
                    mavlink_local_position_ned_t localPosition;
                    mavlink_msg_local_position_ned_decode(&msg, &localPosition);
                    std::cout << "x: " << localPosition.x << ", y: " << localPosition.y << ", z: " << localPosition.z << std::endl;
                    setFlyingObjectLatitude(localPosition.x);
                    setFlyingObjectLongitude(localPosition.y);
                }
                /*if (msg.msgid == 32) {
                    mavlink_local_position_ned_t local_position_ned[sizeof(msg.payload64)/8];
                    printf("\n-- POSITION FRAME --");
                    mavlink_msg_local_position_ned_decode(&msg.payload64, &local_position_ned);
                    printf("x: %d, y: %d, z: %d", local_position_ned->x, local_position_ned->y, local_position_ned->z);
                }*/
                // Packet received
                //std::cout << std::endl << "Received packet: SYS: " << msg.sysid << ", COMP: " << msg.compid << ", LEN: " << msg.len << ", MSG ID: " << msg.msgid << std::endl;
                //std::cout << "payload: " << msg.payload64 << std::endl;
            }
        }
        std::cout << std::endl;
    }
    memset(buf, 0, BUFFER_LENGTH);
}

double GroundControlStation::flyingObjectLatitude() const
{
    return m_flyingObjectLatitude;
}

double GroundControlStation::flyingObjectLongitude() const
{
    return m_flyingObjectLongitude;
}
double GroundControlStation::flyingObjectAltitude() const
{
    return m_flyingObjectAltitude;
}

void GroundControlStation::setFlyingObjectLatitude(const double latitude)
{
    if (latitude == m_flyingObjectLatitude)
        return;

    m_flyingObjectLatitude = latitude;
    emit flyingObjectLatitudeChanged();
}

void GroundControlStation::setFlyingObjectLongitude(const double longitude)
{
    if (longitude == m_flyingObjectLongitude)
        return;

    m_flyingObjectLongitude = longitude;
    emit flyingObjectLongitudeChanged();
}

void GroundControlStation::setFlyingObjectAltitude(const double altitude)
{
    if (altitude == m_flyingObjectAltitude)
        return;

    m_flyingObjectAltitude = altitude;
    emit flyingObjectAltitudeChanged();
}
