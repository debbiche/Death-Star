#include <signal.h> 
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

int main(void){

  int sock;
  struct hostent * host; 
  struct sockaddr_in connecting; 
  int receive;
  char receive_data[5];
  sock = socket(AF_INET, SOCK_STREAM,0);
  host = (struct hostent *)gethostbyname((char *)"127.0.0.1");
  connecting.sin_family = (sa_family_t)AF_INET;
  connecting.sin_port = htons(9600);
  connecting.sin_addr= *((struct in_addr *)host->h_addr);
  memset(&(connecting.sin_zero),'\0',8);
  connect(sock,(struct sockaddr *)&connecting,sizeof(struct sockaddr));

  while(1){
receive = recv(sock,receive_data,5,0);
    receive_data[receive]= '\0';
    printf("%s\n", receive_data);
send(sock,"hiii",5,0);
  }

  return 0;
}
