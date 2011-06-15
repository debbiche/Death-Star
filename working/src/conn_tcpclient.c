/*!***************************************************************************
 * Copyright (C) 2011  <Michal Musialik>
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
 ****************************************************************************
 *  @file conn_tcpclient.c
 *
 *  @brief tcpclient file
 *
 *  @author Michal Musialik
 *  @date 2011-05-07
 *  @details Client part of the wireless connection that is used to send \n
 *   command messages to the drone wirelessly. Command mesags are invoked \n
 *   by GUI that controll the drone. 
 ****************************************************************************/
#include <signal.h> 
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include "conn_tcpclient.h"

#define SERVER_ADDRESS "127.0.0.1" 
#define DEBUG(x) printf("%s",x);

int socket_tcp;
int receiving;
char *data_receiving;
int pid_receiving;


struct hostent * host; 
struct sockaddr_in connecting; 

/*!
  @brief Creating client socket
*/
int socket_create(void){
    if((socket_tcp = socket(AF_INET, SOCK_STREAM,0)) < 0){
        DEBUG("failed to create a socket\n")
        return -1;
    }
    else {
        DEBUG("socket is succesfully created\n")
        return 0;
    }
}


/*!
    @brief Binding socket function
*/
int socket_binding(void) {
    /*Drone adress need to be hadcodded*/
    host = (struct hostent *)gethostbyname((char *)SERVER_ADDRESS);
    connecting.sin_family = (sa_family_t)AF_INET;
    connecting.sin_port = htons(PORT);
    connecting.sin_addr= *((struct in_addr *)host->h_addr);
    memset(&(connecting.sin_zero),'\0',8);/*zeroing rest of struct*/
    return 0;
}

/*!
  @brief Connecting function
*/
int socket_connection(void) {
    if(connect(socket_tcp,(struct sockaddr *)&connecting,sizeof(struct 
	    sockaddr)) < 0) {
        DEBUG("connect()")
	return -1;
    }
    else {
        DEBUG("Client is connected\n")
	socket_receiving();
        return 0; 
    }  

}
/*!
  @brief Receiving data from server
*/
void socket_receiving(void){
    data_receiving = malloc(GPS_BUFFER);
    pid_receiving = fork();
    if(pid_receiving ==0){
        DEBUG("In while loop\n")
	while(1){
	receiving = recv(socket_tcp,data_receiving,sizeof(data_receiving),0);
        data_receiving[receiving]= '\0';
	printf("%s\n", data_receiving);
        }
    }
}

/*!
  @brief Function for sending data over to the server
*/
void send_forward (void){
    DEBUG("Sending foward\n")
    send(socket_tcp,FORWARD,BUFFER_SIZE,0);
}

/*!
  @brief Function for sending data over to the server
*/

void send_back (void){
    DEBUG("Sending back\n") 
    send(socket_tcp,BACK,BUFFER_SIZE,0);
}

/*!
  @brief Function for sending data over to the server
*/

void send_left (void){
    DEBUG("Sending left\n")
    send(socket_tcp,LEFT,BUFFER_SIZE,0);
}

/*!
  @brief Function for sending data over to the server
*/

void send_right (void){
    DEBUG("Sending right\n")
    send(socket_tcp,RIGHT,BUFFER_SIZE,0);
}

/*!
  @brief Function for sending data over to the server
*/

void send_exit(void){
    DEBUG("Shutting\n")
    send(socket_tcp,QUIT,BUFFER_SIZE,0);
    free(data_receiving);
    kill(pid_receiving,SIGTERM);
    CLOSE_SOCKET_TCP;
    
}

/*!
  @brief Function for sending data over to the server
*/

void send_hover(void){
    DEBUG("Hover mode\n")
    send(socket_tcp,TAKE_OFF,BUFFER_SIZE,0);
}

/*!
  @brief Function for sending data over to the server
*/

void send_landing(void){
    DEBUG("landing\n")
    send(socket_tcp,LAND,BUFFER_SIZE,0);
}

/*!
  @brief Function for sending data over to the server
*/

void send_alt_up(void){
    DEBUG("Alt up\n")
    send(socket_tcp,UP,BUFFER_SIZE,0);
}

/*!
  @brief Function for sending data over to the server
*/

void send_alt_down(void){
    DEBUG("Alt down\n")
    send(socket_tcp,DOWN,BUFFER_SIZE,0);
}

/*!
  @brief Function for sending data over to the server
*/

void send_camera(void){
    DEBUG("Camera\n")
    send(socket_tcp,START_CAMERA,BUFFER_SIZE,0);

}

/*!
  @brief Function for sending data over to the server
*/

void send_gps_outdoor(void){
    DEBUG("gps outdoor\n")
    send(socket_tcp,START_OUTDOOR_PATH,BUFFER_SIZE,0);
}

/*!
  @brief Function for sending data over to the server
*/

void send_kill_outdoor(void){
    DEBUG("kill outdoor\n")
    send(socket_tcp,KILL_GPS,BUFFER_SIZE,0);
}

/*!
  @brief Function for sending data over to the server
*/

void send_indoor(void){
    DEBUG("indoor\n")
    send(socket_tcp,START_INDOOR_PATH,BUFFER_SIZE,0);
}

/*!
  @brief Function for sending data over to the server
*/

void send_kill_indoor(void){
    DEBUG("kill indoor\n")
    send(socket_tcp,KILL_INDOOR,BUFFER_SIZE,0);
}

/*!
  @brief Function for sending data over to the server
*/

void send_kill_server(void){
    DEBUG("kill server\n")
    send(socket_tcp,SERVER_SHUT,BUFFER_SIZE,0);
}

/*!
  @brief Function for sending data over to the server
*/

void send_indoor_position(void){
    DEBUG("indoor position\n")
    send(socket_tcp,INDOOR_POSITION,BUFFER_SIZE,0);
}

/*!
  @brief Function for sending data over to the server
*/

void send_outdoor_position(void){
    DEBUG("outdoor position\n")
    send(socket_tcp,OUTDOOR_POSITION,BUFFER_SIZE,0);
}
