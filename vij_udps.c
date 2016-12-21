/* Sample UDP server */

#include <netinet/in.h>

// source : Vijay Yalasangimath <vijayyalasangimath@gmail.com>

#include <stdio.h>
#include <arpa/inet.h>
#include<string.h>

int main()
{
   int sockfd,n;
   struct sockaddr_in servaddr,cliaddr;
   socklen_t len;
   char mesg[1000];
   printf("This is server----------\n");

   sockfd=socket(AF_INET,SOCK_DGRAM,0);

   bzero(&servaddr,sizeof(servaddr));
   servaddr.sin_family = AF_INET;
   servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
   servaddr.sin_port=htons(9999);

   bind(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
  // bind(sockfd,&servaddr,sizeof(servaddr));

      len = sizeof(cliaddr);
      n = recvfrom(sockfd,mesg,1000,0,(struct sockaddr *)&cliaddr,&len);
      mesg[n] = 0;
      printf("Received packet from %s:%d\nData: %s\n it is again send back to client ",inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port), mesg); 

      sendto(sockfd,mesg,strlen(mesg),0,(struct sockaddr *)&cliaddr,sizeof(cliaddr));

      close(sockfd);

}
