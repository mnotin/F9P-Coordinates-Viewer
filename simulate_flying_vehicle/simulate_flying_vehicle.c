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
/* These headers are for QNX, but should all be standard on unix/linux */
#include <stdio.h>
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
#include <stdbool.h> /* required for the definition of bool in C99 */
#endif

/* This assumes you have the mavlink headers on your include path
 or in the same folder as this source file */
#include <mavlink.h>


#define BUFFER_LENGTH 2041 // minimum buffer size that can be used with qnx (I don't know why)

uint64_t microsSinceEpoch();

int main(int argc, char* argv[])
{
    char help[] = "--help";
	
    char target_ip[100];
    
    mavlink_telemetry_data_pack_t mavlinkTelemetryDataPack;
    mavlinkTelemetryDataPack.Latitude = 0;
    mavlinkTelemetryDataPack.Longitude = 0;
    int sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
    struct sockaddr_in gcAddr; 
    struct sockaddr_in locAddr;
    //struct sockaddr_in fromAddr;
    uint8_t buf[BUFFER_LENGTH];
    ssize_t recsize;
    socklen_t fromlen = sizeof(gcAddr);
    int bytes_sent;
    mavlink_message_t msg;
    uint16_t len;
    int i = 0;
    //int success = 0;
    unsigned int temp = 0;
    
    // Check if --help flag was used
    if ((argc == 2) && (strcmp(argv[1], help) == 0))
    {
	printf("\n");
	printf("\tUsage:\n\n");
	printf("\t");
	printf("%s", argv[0]);
	printf(" <ip address of QGroundControl>\n");
	printf("\tDefault for localhost: udp-server 127.0.0.1\n\n");
	exit(EXIT_FAILURE);
    }
	
	
    // Change the target ip if parameter was given
    strcpy(target_ip, "127.0.0.1");
    if (argc == 2)
    {
	strcpy(target_ip, argv[1]);
    }
	
	
    memset(&locAddr, 0, sizeof(locAddr));
    locAddr.sin_family = AF_INET;
    locAddr.sin_addr.s_addr = INADDR_ANY;
    locAddr.sin_port = htons(14551);
	
    /* Bind the socket to port 14551 - necessary to receive packets from qgroundcontrol */ 
    if (-1 == bind(sock,(struct sockaddr *)&locAddr, sizeof(struct sockaddr)))
    {
	perror("error bind failed");
	close(sock);
	exit(EXIT_FAILURE);
    } 
	
	/* Attempt to make it non blocking */
#if (defined __QNX__) | (defined __QNXNTO__)
    if (fcntl(sock, F_SETFL, O_NONBLOCK | FASYNC) < 0)
#else
    if (fcntl(sock, F_SETFL, O_NONBLOCK | O_ASYNC) < 0)
#endif
    {
	fprintf(stderr, "error setting nonblocking: %s\n", strerror(errno));
	close(sock);
	exit(EXIT_FAILURE);
    }
	
	
    memset(&gcAddr, 0, sizeof(gcAddr));
    gcAddr.sin_family = AF_INET;
    gcAddr.sin_addr.s_addr = inet_addr(target_ip);
    gcAddr.sin_port = htons(14550);

    /* Message signature
    uint8_t key[32] = { 0, 0, 0, 0, 0, 0, 0, 0,
    			0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0 };
    mavlink_signing_t signing;
    mavlink_signing_streams_t signing_streams;
	
    memset(key, 0, 32);
    memset(&signing, 0, sizeof(signing));
    memcpy(signing.secret_key, key, 32);
    signing.link_id = (uint8_t)MAVLINK_COMM_0;
    signing.timestamp = 0;
    signing.flags = MAVLINK_SIGNING_FLAG_SIGN_OUTGOING;*/
	
    for (;;)
    {
	printf("Sending data ...\n");
		
	/*Send Heartbeat */
	mavlink_msg_heartbeat_pack(1, 200, &msg, MAV_TYPE_HELICOPTER, MAV_AUTOPILOT_GENERIC, MAV_MODE_GUIDED_ARMED, 0, MAV_STATE_ACTIVE);
	len = mavlink_msg_to_send_buffer(buf, &msg);
	bytes_sent = sendto(sock, buf, len, 0, (struct sockaddr*)&gcAddr, sizeof(struct sockaddr_in));
	
	/* Send Status */
	mavlink_msg_sys_status_pack(1, 200, &msg, 0, 0, 0, 500, 11000, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	len = mavlink_msg_to_send_buffer(buf, &msg);
	bytes_sent = sendto(sock, buf, len, 0, (struct sockaddr*)&gcAddr, sizeof (struct sockaddr_in));
	
	/* Send Local Position */
	mavlink_msg_telemetry_data_pack_pack(1, 200, &msg, microsSinceEpoch(),
	    0, //uint64_t GNSS_Timestamp,
	    mavlinkTelemetryDataPack.Latitude, //int32_t Latitude,
	    mavlinkTelemetryDataPack.Longitude, //int32_t Longitude,
	    0, //uint32_t GNSS_Altitude,
	    0, //int32_t Altitude_Main_Altimeter,
	    0, //int32_t Altitude_Payload_Altimeter,
	    0.0, //float ECEF_Position_X,
	    0.0, //float ECEF_Position_Y,
	    0.0, //float ECEF_Position_Z,
	    0.0, //float ECEF_Velocity_X,
	    0.0, //float ECEF_Velocity_Y,
	    0.0, //float ECEF_Velocity_Z,
	    0.0, //float Quaternion_0,
	    0.0, //float Quaternion_1,
	    0.0, //float Quaternion_2,
	    0.0, //float Quaternion_3,
	    0, //uint32_t Telemetry_Status_Mask,
	    0, //int16_t Air_Speed_U,
	    0, //int16_t Air_Speed_V,
	    0, //int16_t Air_Speed_W,
	    0, //int16_t Air_Temperature,
	    0, //uint16_t Velocity_Horizontal,
	    0, //int16_t Velocity_Vertical,
	    0, //uint16_t Position_Accuracy,
	    0, //uint16_t Speed_Accuracy,
	    0, //int16_t Acceleration_X,
	    0, //int16_t Acceleration_Y,
	    0, //int16_t Acceleration_Z,
	    0, //int16_t Roll_Angle,
	    0, //int16_t Pitch_Angle,
	    0, //int16_t Yaw_Angle,
	    0, //int16_t Angular_Rate_Roll,
	    0, //int16_t Angular_Rate_Pitch,
	    0, //int16_t Angular_Rate_Yaw,
	    0 //uint8_t Satellite_Num,
	    );
	len = mavlink_msg_to_send_buffer(buf, &msg);
	//mavlink_sign_packet(&signing, signing.secret_key, (uint8_t *) &localPosition, sizeof(localPosition),(uint8_t *) &localPosition, sizeof(localPosition), &(mavlink_get_msg_entry(32)->crc_extra)); // Generates the signature of the message
	bytes_sent = sendto(sock, buf, len, 0, (struct sockaddr*)&gcAddr, sizeof(struct sockaddr_in));
	
	/* Send attitude */
	mavlink_msg_attitude_pack(1, 200, &msg, microsSinceEpoch(), 1.2, 1.7, 3.14, 0.01, 0.02, 0.03);
	len = mavlink_msg_to_send_buffer(buf, &msg);
	bytes_sent = sendto(sock, buf, len, 0, (struct sockaddr*)&gcAddr, sizeof(struct sockaddr_in));
		
		
	memset(buf, 0, BUFFER_LENGTH);
	recsize = recvfrom(sock, (void *)buf, BUFFER_LENGTH, 0, (struct sockaddr *)&gcAddr, &fromlen);
	if (recsize > 0)
	{
	    // If we receive something, we do nothing.
	    // Here, we just need to send some data to the other program
	}
	memset(buf, 0, BUFFER_LENGTH);
	sleep(1); // Sleep one second
	mavlinkTelemetryDataPack.Longitude += 1; // Simulate the movement of the flying object
    }
}


/* QNX timer version */
#if (defined __QNX__) | (defined __QNXNTO__)
uint64_t microsSinceEpoch()
{
    struct timespec time;
    
    uint64_t micros = 0;
    
    clock_gettime(CLOCK_REALTIME, &time);  
    micros = (uint64_t)time.tv_sec * 1000000 + time.tv_nsec/1000;
    
    return micros;
}
#else
uint64_t microsSinceEpoch()
{
    struct timeval tv;
    
    uint64_t micros = 0;
    
    gettimeofday(&tv, NULL);  
    micros =  ((uint64_t)tv.tv_sec) * 1000000 + tv.tv_usec;
    
    return micros;
}
#endif
