
//author RAGHAVENDRA M     tcp ip client program  

// #include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
//#include<string.h>
//#include<unistd.h>

int t=1;

void error(char *msg)
{
	 perror(msg);
	 exit(0);
}

int main(int argc,char *argv[])
{
	int sockfd,n,sl,ch;
	char fname[20];
	struct sockaddr_in serv_addr;
	struct hostent *server;
	char host[20],buffer[256],buf[2000];
	int portno;
 
	printf("\n************This is client :");
	bzero(host,20);
  	//printf("\nEnter \n0 - local host \n1 - ip address : "); 
  	//scanf("%d",&ch);
  	
	//if(ch==0)
  		strcpy(host,"127.0.0.1");   // use inet address of the server.  you can optain it using 
  /*	else
  	 {
  	   printf("\nEnter the server ip address :");
  	   scanf("%s",host);              //   "ifconfig"  at root
  	 }  */
 	
//	printf("\nEnter port no :");
  //	scanf("%d",&portno);              //this must be same as servers port number
 //	printf("\nClient:Enter path with filename( file is currently at the server)  : ");
 //	scanf("%s",fname);

        portno = 5000;

         strcpy(fname , "tcps_sim.c");  
          
  
	sockfd=socket(AF_INET,SOCK_STREAM,0);
 
//	 if(sockfd<0)
//	  error("\nerror opening socket\n");
 
 	server=gethostbyname(host);
 
/*	if(server==NULL)
	 {
	  fprintf(stderr,"\nerror,no such host\n");
 	  exit(0);
 	 } */
 
	bzero((struct sockaddr_in *)&serv_addr,sizeof(serv_addr));
 	serv_addr.sin_family=AF_INET;
 	bcopy((char *)server->h_addr,(char *)&serv_addr.sin_addr.s_addr,server->h_length);
 	serv_addr.sin_port=htons(portno);
 
 	connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr));
 	 //  error("\nerror connecting");
  
	sl=strlen(fname);
	n=write(sockfd,fname,strlen(fname));
 //	if(n<0)
   //	  error("\nclient:error writing   to socket");
   	bzero(buf,2000);
 	printf("\nclient:From server following file contents are received  :- \n\n\n");
 
	while(1)
        {
         bzero(buf,2000);    
         if ((n=recv(sockfd, buf, 100, 0)) == -1) 
               perror("recv");
     	 if (n==0)
		break;
         puts(buf);  
	}	     
        
	close(sockfd);   
        exit(0);  
	       
 }
      
      
       
  
  
 
  
  
