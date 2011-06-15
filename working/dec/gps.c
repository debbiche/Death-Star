#include <stdio.h>
#include <string.h>

int main(void){
  // gga time lat lon 
  char test [] = "$GPGGA,123519,4807.038,N,01131.000,E,1,08,0.9,545.4,M,46.9,M,,*47";
  
  char *gga;
  char *time;
  char *lan;
  char *ws;
  char *lon;
  printf("%s\n\n", test);
  gga = strtok(test,",");

   while(gga !=NULL){
   printf("%s\n",gga);
   gga = strtok(NULL,",");
  }

  /* 
  gga = strtok(test,",");
  printf("gga %s\n",gga);
  gga  = strchr(test, ',');

  time = strtok(gga,",");
  printf("time %s\n",time);
  time = strchr(time,',');

  lan = strtok(time,",");
  printf("lan %s\n",lan);
  lan = strchr(lan,',');

  ws = strtok(lan,",");
  printf("ws %s\n", ws);
  ws = strchr(ws,',');

  lon = strtok(ws,",");
  printf("lon %s\n", lon);
  lon = strchr(lon,',');
  */
  

  return 0;
}
