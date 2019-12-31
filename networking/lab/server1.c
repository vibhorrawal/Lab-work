#include<stdio.h>
#include<string.h>
#include<time.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<sys/socket.h>

int main(){
time_t clock;
struct sockaddr_in ip;
memset(&ip,0,sizeof(ip));
int listenConn, conn;
char packet[1025] = {0};
printf("HERE\n");
listenConn = socket(AF_INET,SOCK_STREAM,0);
printf("%d",listenConn);
printf("HERE\n");
ip.sin_family = AF_INET;
ip.sin_addr.s_addr = inet_addr("127.0.0.4");
ip.sin_port = htons(1000);
printf("HERE\n");
bind(listenConn,(struct sockaddr *)&ip,sizeof(ip));
listen(listenConn,20);
printf("HERE\n");
while(1){
printf("Server running...\n");
conn = accept(listenConn, (struct sockaddr *) NULL, NULL);
clock = time(NULL);
snprintf(packet,sizeof(packet),"%s", ctime(&clock));
write(conn, packet, strlen(packet));
close(conn);
}
return 0;
}

