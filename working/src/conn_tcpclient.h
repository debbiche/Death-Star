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
 *
 *  @file conn_tcpclient.h
 *
 *  @brief Header file for conn_tcpclient.c
 *
 *  @author Michal Musialik
 *  @date 2011-05-07
 ****************************************************************************/

#ifndef CONN_TCPCLIENT
#define CONN_TCPCLIENT
#define GPS_BUFFER 30/*Buffer for GPS data*/
#define PORT 9600 
#define BUFFER_SIZE 15/*Buffer controll message handling*/
#define CLOSE_SOCKET_TCP close(socket_tcp)

#define FORWARD "3"
#define BACK "4" 
#define LEFT "5" 
#define RIGHT "6" 
#define UP "7" 
#define DOWN "8" 
#define LAND "9" 
#define TAKE_OFF "10" 
#define KILL_INDOOR "11" 
#define KILL_GPS "12"
#define KILL_SERVER "13" 
#define START_CAMERA "14"
#define START_INDOOR_PATH "30"
#define START_OUTDOOR_PATH "31"
#define INDOOR_POSITION "20"
#define OUTDOOR_POSITION "21"
#define QUIT "quit"
#define SERVER_SHUT "shut_server"

int socket_create(void);
int socket_binding(void);
int socket_connection(void);
void socket_receiving(void);
void send_forward (void);
void send_back (void);
void send_left (void);
void send_right (void);
void send_exit(void);
void send_hover(void);
void send_landing(void);
void send_alt_up(void);
void send_alt_down(void);
void send_camera(void);
void send_kill_server(void);
void send_gps_outdoor(void);
void send_kill_outdoor(void);
void send_indoor(void);
void send_kill_indoor(void);
void send_indoor_position(void);
void send_outdoor_position(void);
#endif
