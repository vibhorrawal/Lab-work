#include<stdio.h>
#include<sys/types.h>
#include <netinet/in.h>
#include<sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>


int main(int argc, char const *argv[]) {
  struct sockaddr_in ipOfServer;
  int createSocket,n;
  char data[1025] = {0};
  createSocket = socket(AF_INET,SOCK_STREAM,0);
  if (createSocket<0) {
    printf("Error creating socket\n");
    return 1;
  }

  ipOfServer.sin_family = AF_INET;
  ipOfServer.sin_addr.s_addr = inet_addr("127.0.0.1");
  ipOfServer.sin_port = htons(2000);

  if(connect(createSocket,(struct sockaddr *) &ipOfServer, sizeof(ipOfServer)) < 0){
    printf("Connection failed\n" );
    return 1;
  }

  while ((n = read(createSocket, data, sizeof(data)-1)) > 0) {
    data[n] = 0;
    fputs(data,stdout);
  }
  if(n<0) printf("input error\n" );
  return 0;
}
