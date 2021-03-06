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
 *  @file conn_tcpclient_main.c 
 *
 *  @brief Main function for client socket
 *
 *  @author Michal Musialik
 *  @date 2011-04-10 
 ****************************************************************************/
#include "conn_tcpclient_main.h"
#include "conn_tcpclient.h"

 
void init(void){
     socket_create();
     socket_binding();
     socket_connection();
  
}
