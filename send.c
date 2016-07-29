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
#define SERVER_IP  "192.168.128.65"

 int main(){
  int s, ret = 0;
  struct sockaddr_in addr;
  char buffer[10240];

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

  ret+= sprintf(buffer+ret,"GET /1.txt HTTP/1.1\r\n");
  ret+= sprintf(buffer+ret,"User-Agent: Wget/1.17.1 (linux-gnu)\r\n");
  ret+= sprintf(buffer+ret,"Accept: */*\r\n");
  ret+= sprintf(buffer+ret,"Accept-Encoding: identity\r\n");
  ret+= sprintf(buffer+ret,"Host: 192.168.128.65\r\n");
  ret+= sprintf(buffer+ret,"Connection: Keep-Alive\r\n\r\n");
  printf("%s", buffer);

  write(s, buffer, sizeof(buffer));
  bzero(buffer, sizeof(buffer));
  recv(s, buffer, sizeof(buffer), 0);
  printf("%s\n", buffer);
//  printf("hello world\n8787\n");
  perror("send");
  exit(1);

}

