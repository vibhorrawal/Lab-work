#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#include <string.h>
int main(int argc, char const *argv[]) {
  struct sockaddr_in ip;
  memset(&ip,0,sizeof(ip));
  char data[1025];
  time_t clock;
  int clientListen, clientConnection;
  clientListen = socket(AF_INET, SOCK_STREAM, 0);
  ip.sin_family = AF_INET;
  ip.sin_addr.s_addr = inet_addr("127.0.0.1");
  ip.sin_port = htons(2000);
  bind(clientListen, (struct sockaddr *) &ip, sizeof(ip));
  listen(clientListen,20);

  while(1){
    printf("Server running\n" );
    clientConnection = accept(clientListen, (struct sockaddr *)NULL, NULL);
    clock = time(NULL);
    snprintf(data,sizeof(data),"%s\n",ctime(&clock));
    write(clientConnection, data, strlen(data));
    close(clientConnection);
  }
  return 0;
}
