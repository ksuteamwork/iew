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

  

 int main(){
  int s, ret = 0;
  struct sockaddr_in addr;
  char buffer[1024];

  if((s = socket(AF_INET, SOCK_STREAM, 0)) < 0){
	perror("socket");
	exit(1);
  }

  bzero(&addr,sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(PORT);
  addr.sin_addr.s_addr = inet_addr(SERVER_IP);

  if(connect(s,(struct sockaddr*) &addr, sizeof(addr)) < 0){
	perror("connect");
 	exit(1);
  }

  perror("send");
  exit(1);

}


