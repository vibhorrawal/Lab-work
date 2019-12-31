#include<stdio.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>
#include<netinet/in.h>
#include<time.h>

int main(){
struct sockaddr_in ip;
memset(&ip,0,sizeof(ip));
int conn,n;
char packet[1025];

conn = socket(AF_INET, SOCK_STREAM,0);

ip.sin_family = AF_INET;
ip.sin_addr.s_addr = inet_addr("127.0.0.4");
ip.sin_port = htons(1000);

if(connect(conn,(struct sockaddr *) &ip, sizeof(ip)) < 0) printf("Connection error\n");

read(conn,packet,sizeof(packet));
printf("%s",packet);

return 0;
}
