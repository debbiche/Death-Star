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

void  main(void){
  int sock;
  int new;
  int reusing_value = 1;
  int ip_buffer;
  int address_length;
    int receive;
    int sending[5];

  struct sockaddr_in server;
  struct sockaddr_in client;
  struct hostent * host ;

  gethostname(ip_buffer , 100);	
  host = ( struct hostent * )gethostbyname(ip_buffer);
   printf("Host IP Address :%s\n", inet_ntoa(*((struct in_addr
  					       *)host->h_addr))); 

  sock = socket(AF_INET,SOCK_STREAM,0);
  setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &reusing_value,
	     sizeof(reusing_value));
  
  server.sin_family = AF_INET; 
  server.sin_port = htons(9600);
  server.sin_addr.s_addr = INADDR_ANY;
  
  
  bind(sock,(struct sockaddr *)&server,sizeof(struct sockaddr));
  listen(sock,2);
  new = accept(sock, (struct sockaddr *)&client,
		    &address_length);

 printf("Client IP is %s and port is : %d \n", inet_ntoa(client.sin_addr),
    ntohs(client.sin_port));

 while(1){
    send(new,"test",5,0);
           receive = recv(new,sending,5,0);
     sending[receive]= '\0';
      printf("%s\n", sending);
   sleep(1);

 }
 
  
}
