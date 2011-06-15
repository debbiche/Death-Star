/*!**************************************************************************
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
 *
 *  @file conn_tcpserver.h
 *
 *  @brief Header file for tcpserver
 *
 *  @author Michal Musialik
 *  @date 2011-05-07
 ****************************************************************************/
#ifndef CONN_TCPSERVER
#define CONN_TCPSERVER
#define IP_BUFFER_LENGTH 200
#define PORT 9600 
#define BUFFER_SIZE 15
#define MAX_NR_OF_CONNECTIONS 3
#define CLOSE_NEW_SOCKET close(new_socket)
#define CLOSE_SOCKET_TCP close(socket_tcp)

//void socket_calib(void);
void host_setup(void);
int socket_create(void);
int socket_reusing(void);
int socket_keep_alive(void);
int socket_binding(void);
int socket_listening(void);
void camera_server(void);
int socket_accept(void);
int data_passing(void);
void data_sending(void);
void message_handling(int new_socket,int parrent_pid);
#endif
