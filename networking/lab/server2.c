#include<stdio.h>
#include<sys/socket.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<time.h>
#include<string.h>

int main(){
  time_t clock;
  struct sockaddr_in ip;
  memset(&ip, 0, sizeof(ip));
  int conn, clientListen;
  char data[1025] = {0};
  conn = socket(AF_INET, SOCK_DGRAM, 0);
  if(conn < 0){
    printf("Socket error\n" );
    return 1;
  }
  ip.sin_family = AF_INET;
  ip.sin_addr.s_addr = inet_addr("127.0.0.6");
  ip.sin_port = htons(2019);

  bind(conn, (struct sockaddr *) &ip, sizeof(ip));
  listen(conn,20);

  while(1){
    printf("Server running\n" );
    clientListen = accept(conn, (struct sockaddr *) NULL, NULL);
    clock = time(0);
    snprintf(data, sizeof(data), "%s\n", ctime(&clock));
    write(clientListen, data, strlen(data));
    close(clientListen);
    sleep(1);
  }
}
