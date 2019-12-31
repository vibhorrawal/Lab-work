#include<stdio.h>
#include<sys/socket.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<string.h>

int main(){
  struct sockaddr_in ip;
  memset(&ip, 0, sizeof(ip));
  int conn,n;
  char data[1025] = {0};
  conn = socket(AF_INET, SOCK_DGRAM, 0);
  if(conn<0){
    printf("socket error\n");
    return 1;
  }
  ip.sin_family = AF_INET;
  ip.sin_addr.s_addr = inet_addr("127.0.0.4");
  ip.sin_port = htons(2019);

  if(connect(conn, (struct sockaddr * ) &ip, sizeof(ip)) < 0){
    printf("conn error\n" );
  }

  while(n = read(conn, data, sizeof(data))){
    data[n] = 0;
    fputs(data, stdout);
  }
  return 0;
}
