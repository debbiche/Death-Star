/*!
 *  @file conn_mask_ui.h
 *
 *  @brief defines used in conn_ui_mask on server side
 *
 *  @author Michal Musialik
 *  @date 2011-05-07
 *  @history    2011-05-07 - adding new values for macros \n
 *              2011-04-13 - uppdating to new standard \n
 * 		2011-05-19 - final revision Michal,Eugene Groshev \n
 ****************************************************************************
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

#ifndef CONN_UI_MASK
#define CONN_UI_MASK
#define FORWARD 3
#define BACK 4 
#define LEFT 5 
#define RIGHT 6 
#define UP 7 
#define DOWN 8 
#define LAND 9 
#define TAKE_OFF 10 
#define KILL_INDOOR 11 
#define KILL_GPS 12
#define KILL_SERVER 13 
#define START_CAMERA 14
#define START_INDOOR_PATH 30
#define START_OUTDOOR_PATH 31
#define INDOOR_POSITION 20
#define OUTDOOR_POSITION 21
#ifdef DEBUG
#define DEBUG_IN(x) printf("%s",x);
#else
#define DEBUG_IN(x)
#endif
void controll_movement(int status);
#endif
