#include <stdio.h>
#include <string.h>

int main(void){

  char test [] = "34.3214213#21.2341255";
  printf("%s\n",test);
  char * pch;
  pch = strtok(test,"#");
  while(pch != NULL){
    printf("%s\n",pch);
    pch = strtok(NULL,"#");
  }

  char *temp;
  char *temp1;
  char *temp2;
  char w[80];
  char tok[] = "#";
  char test2[] = "12.3456";
  char test3[] = "98.7654";
  temp = strcat(w,test2);
  printf("adding 1st char %s\n",temp);
  temp1 = strcat(temp,tok);
  printf("adding # %s\n",temp1);
  temp2 = strcat(temp1,test2);
  printf("adding 2nd char %s\n",temp2);


  
  double a = 12.34;
  double b = 56.78;
  int i;
  char buff[50];
  for (i = 0;i < 10;i++){

  sprintf(buff,"%f",a++);
  printf("double to string %s\n",buff);
  
}
  return 0;
}
