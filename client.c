#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

#define SERV_TCP_PORT 5035


int main(int argc,char*argv[])
{
    int choice;

       int sockfd;
       struct sockaddr_in serv_addr;
       struct hostent *server;
       char buffer[4096];
       sockfd=socket(AF_INET,SOCK_STREAM,0);
       serv_addr.sin_family=AF_INET;
       serv_addr.sin_addr.s_addr=inet_addr("127.0.0.1");
       serv_addr.sin_port=htons(SERV_TCP_PORT);
       printf("\nReady for sending...");
       connect(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
       
       do
       {
       printf("\nEnter the option to send:\n1.create\n2.delete\n3.cat\n4.edit\n5.exit");     
       printf("\nClient: ");
       fgets(buffer,4096,stdin);
       choice=atoi(buffer);
       send(sockfd,buffer,4096,0);
       
       switch(choice)
       {
         case 1:recv(sockfd,buffer,4096,0);
                printf("Serverecho: %s",buffer);
                fgets(buffer,4096,stdin);
                send(sockfd,buffer,4096,0);
         
                recv(sockfd,buffer,4096,0);
                printf("Serverecho: %s",buffer);
                fgets(buffer,4096,stdin);
                send(sockfd,buffer,4096,0);
         
                recv(sockfd,buffer,4096,0);
                printf("Serverecho:   %s",buffer);
                break;
       
  
       
         case 2:recv(sockfd,buffer,4096,0);
                printf("Serverecho: %s",buffer);
                fgets(buffer,4096,stdin);
                send(sockfd,buffer,4096,0);
         
                recv(sockfd,buffer,4096,0);
                printf("Serverecho:      %s",buffer);
                break;
       
         case 3:recv(sockfd,buffer,4096,0);
                printf("Serverecho: %s",buffer);
                fgets(buffer,4096,stdin);
                send(sockfd,buffer,4096,0);
         
         
                recv(sockfd,buffer,4096,0);
                if(buffer[0]=='*')
                {
                    printf("%s",buffer);
                }
                else
                {
                printf("%s",buffer);
                while(1)
                {
                   recv(sockfd,buffer,4096,0);
                   if(buffer[0]=='*')
                   {
                     break;
                   }
                   printf("%s",buffer);
                }
                }
                break;


          case 4:recv(sockfd,buffer,4096,0);
                 printf("Serverecho: %s",buffer);
                 fgets(buffer,4096,stdin);
                 send(sockfd,buffer,4096,0);
         
                 recv(sockfd,buffer,4096,0);
                 printf("Serverecho: %s",buffer);
                 fgets(buffer,4096,stdin);
                 send(sockfd,buffer,4096,0);
         
                 recv(sockfd,buffer,4096,0);
                 printf("Serverecho:   %s",buffer);
                 break;
      
         case 5:exit(0);
      
      default:recv(sockfd,buffer,4096,0);
              printf("Serverecho:   %s",buffer);
              break;
       
       }
       }while(choice!=5);
       
         printf("\n");
         close(sockfd);
         
         
         return 0;
}
