#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/types.h>
#include<netdb.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<stdlib.h>
#define MAX 80
#define PORT 36744
#define SA struct sockaddr

void func(int sockfd)
{
char buff[MAX];
int n;
for(;;)
{
bzero(buff,sizeof(buff));
printf("Enter the string:");
n=0;
while((buff[n++]=getchar())!='\n');
write(sockfd,buff,sizeof(buff));
bzero(buff,sizeof(buff));
read(sockfd,buff,sizeof(buff));
printf("from server:%s",buff);

if((strncmp(buff,"assalamualaikum",15))==0)
{
printf("Enter the string: waalaikumussalam\n");
read(sockfd,buff,sizeof(buff));
printf("from server:%s",buff);
}
if((strncmp(buff,"assalamualaikum",15))!=0)
{
printf(" Enter the string : are you a muslim?\n");
read(sockfd,buff,sizeof(buff));
printf("from server:%s",buff);
}

if((strncmp(buff,"exit",4))==0)
{
printf("Client Exit\n");
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
printf("socket creation failed\n");
exit(0);
}
else
printf("socket successfully created\n");

bzero(&servaddr,sizeof(servaddr));
servaddr.sin_family=AF_INET;
servaddr.sin_addr.s_addr=inet_addr("192.168.189.129");
servaddr.sin_port=htons(PORT);

if(connect(sockfd,(SA*)&servaddr,sizeof(servaddr))!=0)
{
printf("connection with the server failed\n");
exit(0);
}else
printf("connected with the server\n");
func(sockfd);
close(sockfd);
}


#assignment1
# assignment1
# assignment1
#assignment1client
# assignment1client
# assignment1client
