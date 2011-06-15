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
 *  @file conn_frame.c
 *
 *  @brief This is experimantal interface for graphical controll of drone \n 
 *  through WIFI.After connection with the drone is established user is
 * allowed to controll\n
 *  the drone various options.\n
 *
 *  @author Michal Musialik
 *  @date 2011-05-07
 ****************************************************************************/
#include <gtk/gtk.h> 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include "conn_frame.h"
#include "conn_tcpclient.h"
#include "udp_cam/conn_udpclient_main.c"

/*Gtk widgets*/
GtkWidget *window;
GtkWidget *fixed;
GtkWidget *button_quit;
GtkWidget *button_connect;
GtkWidget *button_foward;
GtkWidget *button_back;
GtkWidget *button_left;
GtkWidget *button_right;
GtkWidget *button_hover;
GtkWidget *button_camera;
GtkWidget *button_camera_client;
GtkWidget *button_alt_up;
GtkWidget *button_alt_down;
GtkWidget *button_gps_indoor;
GtkWidget *button_server;
GtkWidget *button_kill_indoor;
GtkWidget *button_gps_in;
GtkWidget *button_landing;
GtkWidget *button_gps_out;
GtkWidget *button_kill_outdoor;
GtkWidget *button_outdoor_pos;
GtkWidget *button_indoor_pos;
GtkWidget *widget;
GtkWidget *text_frame;
GtkWidget *entry;
GtkLabel *label;
gchar *entry_text;
gint position;
char text [TEXT_SIZE];

/*Main*/
int main( int argc, char *argv[]){
    gtk_init(&argc, &argv);
/*Window initization*/  
    window_creation();
    destroy_command();
    info_frame();
    button_exit();
    frame_text_label();  

    button_back_controll();
    button_left_controll();
    button_right_controll();
    button_forward_controll();
    button_altitide_up();
    button_altitide_down();
    button_camera_controll();
    button_camera_start();
    button_landing_command();
    button_hover_command();
    button_gps_outdoor_command();
    button_kill_gps_outdoor();
    button_gps_indoor_command(); 
    button_kill_gps_indoor();
    button_server_command();
    button_connect_to_server();
    button_indoor_position();
    button_outdoor_position();
    gtk_widget_show_all(window);
    gtk_main();
    return 0;
    exit(-1);
}

/*!
  @brief Function for receiving information from the text frame
*/
void enter_callback( GtkWidget *widget, GtkWidget *entry ){
    entry_text = gtk_entry_get_text (GTK_ENTRY (entry));
    indoor_position(entry_text);
    outdoor_position(entry_text);
}

/*!
  @brief Command lable in UI window
*/
void info_frame(void){
    label = gtk_label_new ("Data");
    gtk_fixed_put(GTK_FIXED(fixed), label, 150, 250);
}  

/*!
  @brief Button for moving drone backward
*/
void button_back_controll(void){
    button_back = gtk_button_new_with_label("back");
    gtk_fixed_put(GTK_FIXED(fixed),button_back , 140, 90);
    gtk_widget_set_size_request(button_back, 70, 30);
    g_signal_connect(G_OBJECT(button_back), "clicked", 
        G_CALLBACK(back_controll), G_OBJECT(window));

}

/*!
  @brief Button for moving drone to the left
*/
void button_left_controll(void){
    button_left = gtk_button_new_with_label("turn left");
    gtk_fixed_put(GTK_FIXED(fixed),button_left , 70, 60);
    gtk_widget_set_size_request(button_left, 70, 30);
    g_signal_connect(G_OBJECT(button_left), "clicked", 
        G_CALLBACK(left_controll), G_OBJECT(window));
}

/*!
  @brief Button for moving drone to the right
*/
void button_right_controll(void){
    button_right = gtk_button_new_with_label("turn right");
    gtk_fixed_put(GTK_FIXED(fixed),button_right , 210, 60);
    gtk_widget_set_size_request(button_right, 70, 30);
    g_signal_connect(G_OBJECT(button_right), "clicked", 
        G_CALLBACK(right_controll), G_OBJECT(window));
}

/*!
  @brief Button for moving drone foward
*/
void button_forward_controll(void){
    button_foward = gtk_button_new_with_label("foward");
    gtk_fixed_put(GTK_FIXED(fixed),button_foward , 140, 30);
    gtk_widget_set_size_request(button_foward, 70, 30);
    g_signal_connect(G_OBJECT(button_foward), "clicked", 
        G_CALLBACK(forward_controll), G_OBJECT(window));
}

/*!
  @brief Button for increasing altitude
*/
void button_altitide_up(void){
    button_alt_up = gtk_button_new_with_label("alt_up");
    gtk_fixed_put(GTK_FIXED(fixed), button_alt_up, MENU_X_CORD, 0);
    gtk_widget_set_size_request(button_alt_up, 70, 30);
    g_signal_connect(G_OBJECT(button_alt_up), "clicked", 
         G_CALLBACK(alt_up), G_OBJECT(window));
}

/*!
  @brief Button for decreasing altitide
*/
void button_altitide_down(void){
    button_alt_down = gtk_button_new_with_label("alt_down");
    gtk_fixed_put(GTK_FIXED(fixed), button_alt_down, MENU_X_CORD, 30);
    gtk_widget_set_size_request(button_alt_down, 70, 30);
    g_signal_connect(G_OBJECT(button_alt_down), "clicked", 
        G_CALLBACK(alt_down), G_OBJECT(window));
}

/*!
  @brief Button for starting camera server
*/
void button_camera_controll(void){
    button_camera = gtk_button_new_with_label("camera server");
    gtk_fixed_put(GTK_FIXED(fixed),button_camera , 140, 150);
    gtk_widget_set_size_request(button_camera, 120, 30);
    g_signal_connect(G_OBJECT(button_camera), "clicked", 
        G_CALLBACK(camera_connect), G_OBJECT(window));
}


/*!
  @brief Button for starting camera
*/
void button_camera_start(void){
    button_camera_client = gtk_button_new_with_label("camera start");
    gtk_fixed_put(GTK_FIXED(fixed),button_camera_client , 140, 180);
    gtk_widget_set_size_request(button_camera_client, 120, 30);
    g_signal_connect(G_OBJECT(button_camera_client), "clicked", 
        G_CALLBACK(camera_start), G_OBJECT(window));
}

/*!
  @brief Button for landing command
*/
void button_landing_command(void){
    button_landing = gtk_button_new_with_label("landing");
    gtk_fixed_put(GTK_FIXED(fixed), button_landing, MENU_X_CORD, 60);
    gtk_widget_set_size_request(button_landing, 70, 30);
    g_signal_connect(G_OBJECT(button_landing), "clicked", 
        G_CALLBACK(landing), G_OBJECT(window));
}


/*!
  @brief Button for hover command
*/
void button_hover_command(void){
    button_hover = gtk_button_new_with_label("hover");
    gtk_fixed_put(GTK_FIXED(fixed), button_hover, MENU_X_CORD, 90);
    gtk_widget_set_size_request(button_hover, 70, 30);
    g_signal_connect(G_OBJECT(button_hover), "clicked", 
        G_CALLBACK(hover), G_OBJECT(window));
}

/*!
  @brief Button for starting outdoor mode
*/
void button_gps_outdoor_command(void){
    button_gps_out = gtk_button_new_with_label("outdor");
    gtk_fixed_put(GTK_FIXED(fixed), button_gps_out, MENU_X_CORD, 120);
    gtk_widget_set_size_request(button_gps_out, 70, 30);
    g_signal_connect(G_OBJECT(button_gps_out), "clicked", 
        G_CALLBACK(gps_outdoor), G_OBJECT(window));
}

/*!
  @brief Button for kill outdoor mode
*/
void button_kill_gps_outdoor(void){
    button_kill_outdoor = gtk_button_new_with_label("kill outdoor");
    gtk_fixed_put(GTK_FIXED(fixed), button_kill_outdoor, MENU_X_CORD, 150);
    gtk_widget_set_size_request(button_kill_outdoor, 70, 30);
    g_signal_connect(G_OBJECT(button_kill_outdoor), "clicked", 
        G_CALLBACK(gps_kill_outdoor), G_OBJECT(window));
}

/*!
  @brief Button to start indoor mode
*/
void button_gps_indoor_command(void){
    button_gps_in = gtk_button_new_with_label("indoor");
    gtk_fixed_put(GTK_FIXED(fixed), button_gps_in, MENU_X_CORD, 180);
    gtk_widget_set_size_request(button_gps_in, 70, 30);
    g_signal_connect(G_OBJECT(button_gps_in), "clicked", 
        G_CALLBACK(gps_indoor), G_OBJECT(window));
}

/*!
  @brief Button to kill indoor mode
*/
void button_kill_gps_indoor(void){
    button_kill_indoor = gtk_button_new_with_label("kill indoor");
    gtk_fixed_put(GTK_FIXED(fixed), button_kill_indoor, MENU_X_CORD, 210);
    gtk_widget_set_size_request(button_kill_indoor, 70, 30);
    g_signal_connect(G_OBJECT(button_kill_indoor), "clicked", 
        G_CALLBACK(gps_kill_indoor), G_OBJECT(window));
}


/*!
  @brief Button for kill the server
*/
void button_server_command(void){
    button_server = gtk_button_new_with_label("kill server");
    gtk_fixed_put(GTK_FIXED(fixed), button_server, MENU_X_CORD, 240);
    gtk_widget_set_size_request(button_server, 70, 30);
    g_signal_connect(G_OBJECT(button_server), "clicked", 
        G_CALLBACK(kill_server), G_OBJECT(window));
}


/*!
  @brief Button for quiting UI window
*/
void button_exit(void){
    button_quit = gtk_button_new_with_label("Exit");
    gtk_fixed_put(GTK_FIXED(fixed), button_quit, MENU_X_CORD, 270);
    gtk_widget_set_size_request(button_quit, 70, 30);
    g_signal_connect(G_OBJECT(button_quit), "clicked", 
        G_CALLBACK(command_quit), G_OBJECT(window));
}

/*!
  @brief Button for establising connection to the drone
*/
void button_connect_to_server(void){
    button_connect = gtk_button_new_with_label("Connect");
    gtk_fixed_put(GTK_FIXED(fixed),button_connect , 140, 270);
    gtk_widget_set_size_request(button_connect, 70, 30);
    g_signal_connect(G_OBJECT(button_connect), "clicked", 
        G_CALLBACK(drone_connect), G_OBJECT(window));
}


/*!
  @brief Button for getting indoor positions
*/
void button_indoor_position(void){
    button_indoor_pos = gtk_button_new_with_label("indoor pos");
    gtk_fixed_put(GTK_FIXED(fixed),button_indoor_pos , 0, 270);
    gtk_widget_set_size_request(button_indoor_pos, 70, 30);
    g_signal_connect(G_OBJECT(button_indoor_pos), "clicked", 
        G_CALLBACK(indoor_position), G_OBJECT(window));
}


/*!
  @brief Button for getting outdoor position
*/
void button_outdoor_position(void){
    button_outdoor_pos = gtk_button_new_with_label("outdoor pos");
    gtk_fixed_put(GTK_FIXED(fixed),button_outdoor_pos , 70, 270);
    gtk_widget_set_size_request(button_outdoor_pos, 70, 30);
    g_signal_connect(G_OBJECT(button_outdoor_pos), "clicked", 
         G_CALLBACK(outdoor_position), G_OBJECT(window));
}

/*!
  @brief UI window intiazion
*/
void window_creation(void){
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Gui window");
    gtk_widget_set_size_request (GTK_WIDGET (window), 400, 350);  
    gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER );
    gtk_window_set_resizable(window,FALSE);
    fixed = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(window), fixed);
}

/*!
  @brief Command for destroying UI window
*/
void destroy_command(void){
    g_signal_connect_swapped(G_OBJECT(window), "destroy", 
        G_CALLBACK(command_quit), NULL);

}

/*!
  @brief Frame text label
*/
void frame_text_label(void){
    entry = gtk_entry_new ();
    gtk_container_add(GTK_CONTAINER(window), entry);  
    gtk_entry_set_max_length (GTK_ENTRY (entry), 100);
    gtk_fixed_put(GTK_FIXED(fixed),entry , 1,300);
    position = GTK_ENTRY (entry)->text_length;
    gtk_editable_select_region (GTK_EDITABLE (entry), 0,
        GTK_ENTRY (entry)->text_length);
    g_signal_connect (entry, "activate", G_CALLBACK (enter_callback), entry);
}

/*!
  @brief Function for sending command to the drone 
*/

void landing(void){
  gtk_label_set_text(label,"landing");
  send_landing();
}


void camera_start(void){
  gtk_label_set_text(label,"starting camera");
  system("vlc mms://127.0.0.1:8090/test.asf &");
}
/*!
  @brief Function for sending command to the drone 
*/

void back_controll(void){
    gtk_label_set_text(label,"back");
    send_back();
}

/*!
  @brief Function for sending command to the drone 
*/

void left_controll(void){
    gtk_label_set_text(label,"left");
    send_left();
}

/*!
  @brief Function for sending command to the drone 
*/

void right_controll(void){
    gtk_label_set_text(label,"right");
    send_right();
}

/*!
  @brief Function for sending command to the drone 
*/

void forward_controll(void){
    gtk_label_set_text(label,"forward");
    send_forward();
}

/*!
  @brief Function for sending command to the drone 
*/

void alt_up(void){
    gtk_label_set_text(label,"alt up");
    send_alt_up();
}

/*!
  @brief Function for sending command to the drone 
*/

void alt_down(void){
    gtk_label_set_text(label,"alt down");
    send_alt_down();
}

/*!
  @brief Function for sending command to the drone 
*/

void camera_connect(void){
    gtk_label_set_text(label,"camera");
    /*command to start receiving camera remotly*/
    cam_client_init();
    // system("./udpc");
    send_camera();
}

/*!
  @brief Function for sending command to the drone 
*/

void hover(void){
    gtk_label_set_text(label,"hover");
    send_hover();
}

/*!
  @brief Function for sending command to the drone 
*/

void gps_outdoor(void){
    gtk_label_set_text(label,"gps outdoor");
    send_gps_outdoor();
}

/*!
  @brief Function for sending command to the drone 
*/

void gps_kill_outdoor(void){
    gtk_label_set_text(label,"kill_outdoor");
    send_kill_outdoor();
}

/*!
  @brief Function for sending command to the drone 
*/
void gps_indoor(void){
    gtk_label_set_text(label,"gps indoor");
    send_indoor();
}

/*!
  @brief Function for sending command to the drone 
*/

void gps_kill_indoor(void){
    gtk_label_set_text(label,"kill indoor");
    send_kill_indoor();
}

/*!
  @brief Function for sending command to the drone 
*/

void kill_server(void){
    gtk_label_set_text(label,"kill server");
    send_kill_server();
}

/*!
  @brief Function for sending command to the drone 
*/

void command_quit(void){
    gtk_label_set_text(label,"quit");
    gtk_main_quit ();
    send_exit();
}

/*!
  @brief Function for sending command to the drone 
*/

void drone_connect(void){
    gtk_label_set_text(label,"connect");
    init();
}

/*!
  @brief Function for sending command to the drone 
*/

void indoor_position(char text[TEXT_SIZE]){
    gtk_label_set_text(label,"indoor position\n");
    send_indoor_position();
}

/*!
  @brief Function for sending command to the drone 
*/

void outdoor_position(char text[TEXT_SIZE]){
    gtk_label_set_text(label,"outdoor_position");
    send_outdoor_position();
}

