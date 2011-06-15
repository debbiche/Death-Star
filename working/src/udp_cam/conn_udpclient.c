/*!
 *  @file conn_udpclient.c
 *
 *  @brief updclient for camera
 *
 *  @author Michal Musialik,Ali Issa
 *  @date 2011-05-17 - initiazing client
 *  @ref http://www.binarii.com/files/papers/c_sockets.txt
 ****************************************************************************
 * Copyright (C) 2011  <Michal Musialik, Ali Issa>
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


#include "conn_udpclient.h"

struct sockaddr_in server;
struct sockaddr_in client;
struct hostent *host;

int sock;
int len = sizeof(struct sockaddr_in);
int byte;
char data [CAM_CLIENT_BUFFER_SIZE];
char check[BUFFER_CHECK_SIZE] = "check";

/*!
  @brief Assigning ip adress
*/
void cam_client_socket_host(void){
    host= (struct hostent *) gethostbyname((char *)"127.0.0.1");
}

/*!
  @brief Creating socket
*/
void cam_client_socket_create(void){
   if((sock = socket(AF_INET, SOCK_DGRAM, 0))<0){
   perror("socket()");
}
    else{
    printf("socket ok\n");
    }
}

/*!
  @brief Biding sokcet
*/
void cam_client_socket_address_bind(void){
    client.sin_family = AF_INET;
    client.sin_port = htons(CAM_CLIENT_PORT);
    client.sin_addr = *((struct in_addr *)host->h_addr);
}

/*!
  @brief Sending a start camera command to server
*/
void cam_client_socket_server_check(void){
    sendto(sock,check,sizeof(check),0,(struct sockaddr *)&client,sizeof
    (struct sockaddr_in));
    close(sock);
}
