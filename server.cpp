#include<iostream>
#include<arpa/inet.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <netdb.h>

using namespace std;

void error( char *msg)
{
 perror(msg);
 exit(EXIT_FAILURE);
}

int main()
{
 int sockfd, proto, clen;
 struct sockaddr_in saddr, caddr;
 struct sockaddr *sa , *ca;
 
 // Получаем номер протокола UDP
 proto=getprotobyname("udp")->p_proto;
	
 sockfd = socket(AF_INET,SOCK_DGRAM,proto);
 
 
 saddr.sin_family = AF_INET;
 saddr.sin_port = htons(53000);
 saddr.sin_addr.s_addr = INADDR_ANY;

 if(bind(sockfd, sa, sizeof(saddr))==-1) {
		perror("udps: не удается занять порт");
		exit(1);
	}

 char buffer[256];
 caddr.sin_family=AF_INET;
 clen = sizeof(caddr);

 cout<<"\ngoing to recv\n";
 int rc= recvfrom(sockfd,buffer,sizeof(buffer),0,ca,&clen);
 if(rc<0)
 {
 cout<<"ERROR READING FROM SOCKET";
 }
 cout<<"\n the message received is : "<<buffer<<endl;
}
