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
 *  @file conn_frame.h
 *
 *  @brief This is a header file that contain prtotype used frame.c
 *  @author Michal Musialik
 *
 *  @date 2011-05-07
 ****************************************************************************/



#ifndef CONN_FRAME
#define CONN_FRAME
#include <gtk/gtk.h>
#define TEXT_SIZE 50
#define DEBUG(x) printf("%s",x);
#define MENU_X_CORD 330

void window_creation(void);
void destroy_command(void);
void info_frame(void);
void button_exit(void);
void button_back_controll(void);
void button_left_controll(void);
void button_right_controll(void);
void button_forward_controll(void);
void button_altitide_up(void);
void button_altitide_down(void);
void button_camera_controll(void);
void button_camera_start(void);
void button_landing_command(void);
void button_hover_command(void);
void button_gps_outdoor_command(void);
void button_kill_gps_outdoor(void);
void button_gps_indoor_command(void); 
void button_kill_gps_indoor(void);
void button_server_command(void);
void button_connect_to_server(void);
void  button_indoor_position(void);
void  button_outdoor_position(void);
void back_controll(void);
void left_controll(void);
void left_controll(void);
void right_controll(void);
void forward_controll(void);
void alt_up(void);
void alt_down(void);
void camera_connect(void);
void camera_start(void);
void hover(void);
void gps_outdoor(void);
void gps_kill_outdoor(void);
void gps_indoor(void);
void gps_kill_indoor(void);
void kill_server(void);
void command_quit(void);
void indoor_position(char* text);
void outdoor_position(char* text);
void landing(void);
void drone_connect(void);
void enter_callback(GtkWidget *widget, GtkWidget *entry );
void frame_text_label(void);
#endif
