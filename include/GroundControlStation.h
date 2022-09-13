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

#ifndef GROUNDCONTROLSTATION_H
#define GROUNDCONTROLSTATION_H

#include <QTimer>
#include <QObject>
#include <QString>
#include <QtQml>

/* These headers are for QNX, but should all be standard on unix/linux */
#include <errno.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>
#if (defined __QNX__) | (defined __QNXNTO__)
/* QNX specific headers */
#include <unix.h>
#else
/* Linux / MacOS POSIX timer headers */
#include <sys/time.h>
#include <time.h>
#include <arpa/inet.h>
#endif

/* This assumes you have the mavlink headers on your include path
 or in the same folder as this source file */
#include <mavlink/v2.0/AGU/AGU_MAVLINK/mavlink.h>

#define BUFFER_LENGTH 2041 // minimum buffer size that can be used with qnx (I don't know why)

class GroundControlStation : public QObject
{
    Q_OBJECT
    Q_PROPERTY(double flyingObjectLatitude READ flyingObjectLatitude WRITE setFlyingObjectLatitude NOTIFY flyingObjectLatitudeChanged)
    Q_PROPERTY(double flyingObjectLongitude READ flyingObjectLongitude WRITE setFlyingObjectLongitude NOTIFY flyingObjectLongitudeChanged)
    Q_PROPERTY(double flyingObjectAltitude READ flyingObjectAltitude WRITE setFlyingObjectAltitude NOTIFY flyingObjectAltitudeChanged)
    QML_ELEMENT

public:
    explicit GroundControlStation(QObject *parent = nullptr);

    double flyingObjectLatitude() const;
    double flyingObjectLongitude() const;
    double flyingObjectAltitude() const;

    void setFlyingObjectLatitude(const double latitude);
    void setFlyingObjectLongitude(const double longitude);
    void setFlyingObjectAltitude(const double altitude);

signals:
    void flyingObjectLatitudeChanged();
    void flyingObjectLongitudeChanged();
    void flyingObjectAltitudeChanged();

public slots:
    void UpdateData();

private:
    void configureMAVLink();

    double m_flyingObjectLatitude;
    double m_flyingObjectLongitude;
    double m_flyingObjectAltitude;

    QTimer *m_timer;

    char m_target_ip[100];
    float m_position[6];
    uint8_t buf[BUFFER_LENGTH];
    socklen_t m_fromlen;
    int m_sock;
    ssize_t m_recsize;
    unsigned int m_temp;
    struct sockaddr_in m_gcAddr;
    struct sockaddr_in m_locAddr;
    int m_bytes_sent;
    mavlink_message_t m_msg;
    uint16_t m_len;
    int m_i;
};

#endif // GROUNDCONTROLSTATION_H
