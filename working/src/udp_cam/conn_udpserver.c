/*!
 *  @file conn_udpserver.c
 *
 *  @brief server
 *
 *  @author Michal Musialik,Ali Issa
 *  @date 2011-05-17 - initiazing udpserver
 *  @ref http://www.binarii.com/files/papers/c_sockets.txt
 *  @detailed This is a udp server that start camra ffserver and ffmpeg.
***************************************************************************
 * Copyright (C) 2011  <Michal Musialik,Ali Issa>
 * 
 * This program is free software: you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 ****************************************************************************/

#include "conn_udpserver.h"

struct sockaddr_in server;
struct sockaddr_in client;

int sock;
int len = sizeof(struct sockaddr_in);
int byte;
char check[CAM_SERVER_BUFFER_SIZE];

/*!
  @brief Creating UDP socket
*/
void cam_server_create_socket(void){ 
    if((sock=socket(AF_INET,SOCK_DGRAM,0))<0){
        perror("socket()");
    }
    else{
        printf("socket ok\n");
    }  
}

/*!
  @brief Binding UDP socket
*/
void cam_server_socket_address_bind(void){
    server.sin_family = AF_INET;
    server.sin_port = htons(CAM_SERVER_PORT);
    server.sin_addr.s_addr =INADDR_ANY;
    if (bind (sock,(struct sockaddr *)&server,sizeof(server))<0){
        perror("bind()\n");
    }
    else{
        printf("bind ok\n");
    }
}

/*!
  @breif Receiving start ffserver & ffmpeg command from client
*/
void cam_server_socket_server(void){
    byte = recvfrom(sock,check,sizeof(check),0,(struct sockaddr *)&client,
    &len);
    check[byte] = '\0';
    printf("%s\n",check);
    if((strcmp(check,"check"))==0){
        printf("cam\n");
        system("ffserver & ffmpeg -r 15 -s 352x288 -f video4linux2 -i /dev/video0 http://localhost:8090/feed1.ffm > /dev/null 2>/dev/null &");
    }
    close(sock);
}
