/*!
 *  @file conn_mask_ui.c
 *
 *  @brief tcpclient file
 *
 *  @author Michal Musialik
 *  @date 2011-05-07
 *  @history    2011-05-07 - changing to switch \n 
 *              2011-05-13 - adding nav functions \n
 * 		2011-05-19 - final revision Michal,Eugene Groshev \n
 *
 *  @details This a mask that after receiving a value from the server\n
 *  do a selection by using a switch.
 * ***************************************************************************
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
 ****************************************************************************/


#include "conn_ui_mask.h"
#include <stdio.h>
#include "conn_tcpserver.h"

/*
These includes and values are dirrectly used in motor module

#include "port_test.c"
#include "proto_serial_port.h"
#include "proto_serial_comm.h"

static int32_t portHandle;

uint8_t alt_up  = 0x01;
uint8_t alt_down = 0x02;
uint8_t back  = 0x03;
uint8_t forward  = 0x04;
uint8_t left  = 0x05;
uint8_t right  = 0x06;
uint8_t hover = 0x07;
uint8_t land  = 0x08;
*/

void controll_movement(int identifier){
// portHandle = proto_serialOpen();
    switch(identifier){
        case FORWARD:
        DEBUG_IN("Going forward\n")
// proto_serialSendUICommandMsg(portHandle, forward);
        break; 
        case BACK:
        DEBUG_IN("Going back\n")
// proto_serialSendUICommandMsg(portHandle, back);
        break;
        case LEFT:
        DEBUG_IN("Going left\n")
// proto_serialSendUICommandMsg(portHandle, left);
        break;  
        case RIGHT:
        DEBUG_IN("Going right\n")
//proto_serialSendUICommandMsg(portHandle,right);
        break;
        case UP:
        DEBUG_IN("Going up\n")
//proto_serialSendUICommandMsg(portHandle,alt_up);
        break;
        case DOWN:
        DEBUG_IN("Going down\n")
//proto_serialSendUICommandMsg(portHandle,alt_down);
        break; 
        case LAND:
        DEBUG_IN("land\n")
//proto_serialSendUICommandMsg(portHandle,land);
        break;
        case TAKE_OFF:
        DEBUG_IN("taking off\n")
//proto_serialSendUICommandMsg(portHandle,hover);
        break;
        case KILL_INDOOR:
        DEBUG_IN("kill indoor\n")
        break;
        case KILL_GPS:
        DEBUG_IN("kill gps\n")
        break;
        case KILL_SERVER:
        DEBUG_IN("kill server\n")
        break; 
        case START_CAMERA:
        DEBUG_IN("starting camera\n")  
        break;
        case START_INDOOR_PATH:
        DEBUG_IN("start indoor path\n")
        break; 
        case START_OUTDOOR_PATH:
        DEBUG_IN("start outdoor path\n")
        break;
        case INDOOR_POSITION:
        DEBUG_IN("indoor position\n")
        break;
        case OUTDOOR_POSITION:
        DEBUG_IN("outdoor position\n")
        break;
     }
}

