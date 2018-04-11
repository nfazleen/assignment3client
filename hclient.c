#include<stdio.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<stdlib.h>
#include<string.h>
#include<arpa/inet.h>
#include<unistd.h>
#define MAX 80
#define PORT 36744
#define SA struct sockaddr

void func(int sockfd)
{
char buff[MAX];
int n;
for(;;)
{
bzero(buff,MAX);
printf("Enter the string: ");
n=0;
while((buff[n++]=getchar())!='\n');
write(sockfd,buff,sizeof(buff));
bzero(buff,sizeof(buff));
read(sockfd,buff,sizeof(buff));
printf("From server:%s",buff);

if((strncmp("a",buff,1))==0)
{
//read(sockfd,buff,sizeof(buff));
printf("From server:%s To server: ",buff);
bzero(buff,MAX);
n=0;
while((buff[n++]=getchar())!='\n');
write(sockfd,buff,sizeof(buff));
} 

if((strncmp(buff,"exit",4))==0)
{
printf("Client exit\n");
break;
}
}
}

int main()
{
int sockfd,connfd;
struct sockaddr_in servaddr,cli;
sockfd=socket(AF_INET,SOCK_STREAM,0);

if(sockfd==-1)
{
printf("Socket creation failed\n");
exit(0);
}
else
printf("Socket created\n");

bzero(&servaddr,sizeof(servaddr));
servaddr.sin_family=AF_INET;
servaddr.sin_addr.s_addr=inet_addr("192.168.189.129");
servaddr.sin_port=htons(PORT);

if(connect(sockfd,(SA*)&servaddr,sizeof(servaddr))!=0)
{
printf("Connection failed\n");
exit(0);
}
else
printf("Connected\n");
func(sockfd);
close(sockfd);
}

