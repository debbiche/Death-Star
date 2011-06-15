/*! * ***************************************************************************
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
 *  @file conn_tcpserver.c
 *
 *  @brief  file for tcpserver
 *
 *  @author Michal Musialik
 * 
 ****************************************************************************/
#include "udp_cam/conn_udpserver_main.c"
#include "conn_ui_mask.h"
#include "conn_tcpserver.h"
#include "conn_tcpserver_main.h"
#include <stdio.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>
#include <signal.h>
#include <stddef.h>
#include <resolv.h>
#include <fcntl.h>

int socket_tcp; 
int new_socket;
int receive; 
int sending; 
int address_length; 
int reusing_value = 1;
char* ip_buffer;
char* receive_data;
int pid;
int pid2;
int parrent_pid;
int pid_camera;
int pid_sending;
int keepalive_value;
socklen_t keepalive_length = sizeof(keepalive_value);
int atio_temp;/*variable for parsing from string to int*/ 

struct sockaddr_in server;
struct sockaddr_in client;
struct hostent * host ;

/*!
    @brief Function to get hosts IP information
*/
void host_setup(void){
    ip_buffer = malloc(IP_BUFFER_LENGTH);
    gethostname(ip_buffer , IP_BUFFER_LENGTH);	
    host = ( struct hostent * )gethostbyname(ip_buffer);
#ifdef DEBUG_IN_NR2
    printf("Host name : %s\n", host->h_name) ;
    printf("Host IP Address :%s\n", inet_ntoa(*((struct in_addr
*)host->h_addr))); 
#endif
}

/*! 
    @brief Function for socket creation
*/

int socket_create(void){
     if(( socket_tcp = socket(AF_INET,SOCK_STREAM,0))==-1){
     DEBUG_IN("create()")
     return 1;   
}
     else{
     DEBUG_IN("Created tcp socket\n")
     return 0;
     }
 }

/*!
   @brief Function for socket reusage
*/
int socket_reusing(void){
     if (setsockopt(socket_tcp, SOL_SOCKET, SO_REUSEADDR, &reusing_value,
         sizeof(reusing_value)) < 0){
     DEBUG_IN("setsockopt()")
     return 1;          
}
     else{
     DEBUG_IN("Reusing socket\n")
     return 0;
     }
}



/*!
   @brief Function for keeping socket alive
*/
int socket_keep_alive(void){
    if(getsockopt(socket_tcp, SOL_SOCKET, SO_KEEPALIVE, &keepalive_value,
    &keepalive_length) < 0) {
    DEBUG_IN("getsockopt()")
    return 1;      
}
   else{
   #ifdef DEBUG_IN_NR2
   printf("Socket is keept %s\n", (keepalive_value ? "alive." : "dead."));
   #endif
   return 0;
   }
}

/*!
   @brief Function for binding socket
*/
int socket_binding(void){
    server.sin_family = AF_INET; 
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = INADDR_ANY;
    if((bind(socket_tcp,(struct sockaddr *)&server,sizeof(struct
sockaddr)))==-1){  
    DEBUG_IN("bind()")
    return 1;
}
    else{
    DEBUG_IN("Binding server socket\n");
    return 0; 
    }
}

/*!
   @brief Function for listening
*/
int socket_listening(void){
    if((listen(socket_tcp, MAX_NR_OF_CONNECTIONS))<0){
    DEBUG_IN("listen()")
    return 1;
}
    else{
    DEBUG_IN("Listening for connections\n")
    return 0; 
    }
}

/*!
   @brief Function for server camera
*/

void camera_server(void){
    pid_camera=fork();    
    if(pid_camera == 0){
      DEBUG_IN("Camera server on\n");
      cam_server_init();
    }

}

/*!
   @brief Function for accepting incomming sockets
*/
int socket_accept(void){
    if(( new_socket = accept(socket_tcp, (struct sockaddr *)&client,
    &address_length))<0){
    DEBUG_IN("accept()")
    return 1;
}
    else{ 
    #ifdef DEBUG_IN_NR2
    printf("Client IP is %s and port is : %d \n", inet_ntoa(client.sin_addr),
    ntohs(client.sin_port));
    #endif
    return 0;  
    } 
}
/*!
   @brief Function sending data to client
*/

void data_sending(void){
    while(1){
    send(new_socket,"hi",2,0);
    sleep(1);
    printf("sending\n");
   }
}
/*!
   @brief Function that handles data passing. 
   @details In here we fork the process for different purosses, one of the\n
   fork is to keep drone socket running when the client is dissconnected\n
   so that reconnection can be established.
 */
int data_passing(void){
 /*
   @brief Main while loop 
 */ 
  
    while(1){
    socket_accept();
      
    pid = fork();
        if (pid < 0){      
        DEBUG_IN("pid()")
        exit(1);
        }
    if(pid==0){
#ifdef DEBUG_IN_NR2
    printf("receive---------%d\n",getpid());
#endif
    CLOSE_SOCKET_TCP;
    message_handling(new_socket,parrent_pid);
    CLOSE_NEW_SOCKET;
    exit(0);   
    }
    else{
        CLOSE_NEW_SOCKET;
    }
    if (pid2 ==0){
#ifdef DEBUG_IN_NR2
      printf("Sending child.....%d\n",getpid());
#endif
    }
#ifdef DEBUG_IN_NR2
    printf("Parent ..... %d\n",getpid());
#endif
    }
    CLOSE_SOCKET_TCP;
    return 0;
}


/*!
   @brief Function for handling all data trafic
*/
void message_handling(int new_socket,int parrent_pid){

    receive_data = malloc(BUFFER_SIZE);
    while(1){
        pid_sending=fork();
        if(pid_sending==0){
	data_sending();
    }
    receive = recv(new_socket,receive_data,BUFFER_SIZE,0);
    receive_data[receive]= '\0';
/*!
   @brief Closing client socket
*/
    if (strcmp(receive_data,"quit")==0){
    CLOSE_NEW_SOCKET;
    DEBUG_IN("Closing client\n")
    break;	   
}
/*!
   @brief Closing server socket
*/
    else if (strcmp(receive_data,"shut_server")==0){
    DEBUG_IN("Shutting server\n")
      kill(pid_camera,SIGTERM);
    kill(parrent_pid,SIGTERM);
    free(ip_buffer);
    free(receive_data);
}   
   else{
/*!
  @brief Reading incomming data and sending to controll_movement
*/
#ifdef DEBUG_IN_NR2
     printf("%s\n", receive_data); 
#endif
     atio_temp = atoi(receive_data);
     controll_movement(atio_temp);
   }
}
}
