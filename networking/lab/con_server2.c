#include<stdio.h>
#include<sys/socket.h>
#include<unistd.h>
#include<time.h>
#include<string.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include <stdlib.h>


int main(){
time_t clock;
struct sockaddr_in ip;
memset(&ip,0,sizeof(ip));
char data[1025] = {0};
int conn, clientListen;
conn = socket(AF_INET,SOCK_STREAM,0);
ip.sin_family = AF_INET;
ip.sin_addr.s_addr = inet_addr("127.0.0.4");
ip.sin_port = htons(2019);

bind(conn,(struct sockaddr *)&ip,sizeof(ip));
listen(conn,20);

while(1){
printf("server running...\n");
clientListen = accept(conn, (struct sockaddr *) NULL, NULL);

if(fork() == 0){
close(conn);
snprintf(data,sizeof(data),"hahaha");
write(clientListen,data,strlen(data));
exit(0);
}
close(clientListen);
}
return 0;
}
