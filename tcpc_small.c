#include<stdio.h> 
#include<arpa/inet.h>

int main(int argc,char **argv) 
{ 
 int cs,n; 
 int bufsize=1024; 
 char *buffer=malloc(bufsize); 
 char fname[255]; 
   struct sockaddr_in address; 
 address.sin_family=AF_INET; 
 address.sin_port=htons(15000); 
// inet_pton(AF_INET,argv[1],&address.sin_addr); 

  inet_pton(AF_INET,"127.0.0.1",&address.sin_addr); 
 
 cs=socket(AF_INET,SOCK_STREAM,0); 
 connect(cs,(struct sockaddr *)&address,sizeof(address)); 
 printf("\nEnter filename: ");
 //scanf("%s",fname); 
 strcpy(fname,"tcp.sh");
 send(cs,fname,255,0); 
 while((recv(cs,buffer,bufsize,0))>0) 
 printf("%s",buffer); 
 printf("\nEOF\n"); 
 return close(cs); 
} 
