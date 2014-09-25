#include<iostream>
#include<arpa/inet.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;

void error( char *msg)
{
 perror(msg);
 exit(EXIT_FAILURE);
}
int main()
{
 int sockfd;
 sockfd = socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);
 struct sockaddr_in serv;
 
 serv.sin_family = AF_INET;
 serv.sin_port = htons(53000);
<<<<<<< HEAD
 serv.sin_addr.s_addr = inet_addr("127.0.0.2");
=======
 serv.sin_addr.s_addr = inet_addr("127.0.0.21");
>>>>>>> 14e2dfaff2b65411bdcb50dab641ef9da5bb00af

 if(bind(sockfd, (struct sockaddr *)&serv, sizeof(serv))==-1) {
		perror("udps: не удается занять порт");
		exit(1);
	}


 char buffer[256];
 socklen_t m = sizeof(serv);
 cout<<"\ngoing to send\n";
 cout<<"\npls enter the mssg to be sent\n";
 fgets(buffer,256,stdin);
 sendto(sockfd,buffer,sizeof(buffer),0,(struct sockaddr *)&serv,m);

}
