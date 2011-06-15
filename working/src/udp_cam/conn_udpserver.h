/*!
 *  @file conn_udpserver.h
 *
 *  @brief tcpserver header file
 *
 *  @author Michal Musialik,Ali Issa
 *  @date 2011-05-17 - initiazing udpserver
 *
***************************************************************************
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

#define CAM_SERVER_BUFFER_SIZE 5
#define CAM_SERVER_PORT 9000

void cam_server_create_socket(void);
void cam_server_socket_address_bind(void);
void cam_server_socket_server(void);
