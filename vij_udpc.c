/* Sample UDP client */

#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include<string.h>


int main()
{
   int sockfd,n;
   struct sockaddr_in servaddr,cliaddr;
   char sendline[1000], recvline[1000],host[30],mesg[1000];

   socklen_t len;
   len = sizeof(cliaddr);
   printf("This is Client------------\n");
 //  printf("Enter the IP address:"); 
 //  scanf("%s",host);
 
   strcpy(host,"127.0.0.1");

   sockfd=socket(AF_INET,SOCK_DGRAM,0);

   bzero(&servaddr,sizeof(servaddr));
   servaddr.sin_family = AF_INET;
   servaddr.sin_addr.s_addr=inet_addr(host);
   servaddr.sin_port=htons(9999);


      printf("Enter the text to be sent:");
      scanf("%s",sendline);

      sendto(sockfd,sendline,strlen(sendline),0,(struct sockaddr *)&servaddr,sizeof(servaddr));
      printf("Succesfully sent\n");

      n = recvfrom(sockfd,mesg,1000,0,(struct sockaddr *)&servaddr,&len);
      mesg[n] = 0;
      printf("Echo back : Received packet: %s\n", mesg); 
      close(sockfd);

}
