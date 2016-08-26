#include<sys/stat.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<strings.h>

#define PORT  80
#define SERVER_IP  "192.168.128.95"

 int main(int argc, char argv[]){
  int s, ret = 0, len, opt;
  struct sockaddr_in addr;
  char buffer[2048];
  FILE *fp;

    

  if((s = socket(AF_INET, SOCK_STREAM, 0)) < 0){
	perror("socket");
	exit(1);
  }
  
  while((opt = getopt(argc, argv, "ipr:")) != -1){
   switch(opt){
   case 'i':
    

  bzero(&addr,sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(PORT);
  addr.sin_addr.s_addr = inet_addr(SERVER_IP);

  if(connect(s,(struct sockaddr*) &addr, sizeof(addr)) < 0){
	perror("connect");
 	exit(1);
  }

  ret+= sprintf(buffer+ret,"GET /2.txt HTTP/1.1\r\n");
  ret+= sprintf(buffer+ret,"User-Agent: Wget/1.17.1 (linux-gnu)\r\n");
  ret+= sprintf(buffer+ret,"Accept: */*\r\n");
  ret+= sprintf(buffer+ret,"Accept-Encoding: identity\r\n");
  ret+= sprintf(buffer+ret,"Host: 192.168.128.95\r\n");
  ret+= sprintf(buffer+ret,"Connection: Keep-Alive\r\n\r\n");
  printf("%s", buffer);
 
  write(s, buffer, sizeof(buffer));  
  bzero(buffer, sizeof(buffer));
  recv(s, buffer, sizeof(buffer), 0); 
  printf("%s\n", buffer);
  bzero(buffer, sizeof(buffer));
  fp=fopen("2.txt","w");
   do{
    fprintf(fp,"%s",buffer);
    printf("%s\n",buffer);
    bzero(buffer, sizeof(buffer));
   }while(len = recv(s, buffer, sizeof(buffer), 0));
  perror("send");
  exit(1);
 
}


 

 
