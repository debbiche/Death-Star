/*!
 *  @file conn_udpserver_main.c
 *
 *  @brief main server
 *
 *  @author Michal Musialik,Ali Issa
 *  @date 2011-05-17 - main for udpserver
 *
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
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include "conn_udpserver.c"

int cam_server_init(void){
    cam_server_create_socket();
    cam_server_socket_address_bind();
    cam_server_socket_server();
    return 0;
}

/*
int main(void){
    cam_server_init();
    return 0;
}

*/