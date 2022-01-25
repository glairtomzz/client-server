#include<stdio.h>
#include<netinet/in.h>
#include<netdb.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#define SERV_TCP_PORT 5035

int main(int argc,char**argv)
{
      int choice;
         FILE *fptr;
       int sockfd,newsockfd,clength,r;
       struct sockaddr_in serv_addr,cli_addr;
       char buffer[4096],content[4096],c;
       sockfd=socket(AF_INET,SOCK_STREAM,0);
       serv_addr.sin_family=AF_INET;
       serv_addr.sin_addr.s_addr=INADDR_ANY;
       serv_addr.sin_port=htons(SERV_TCP_PORT);
       printf("\nStart");
       bind(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
       printf("\nListening...");
       printf("\n");
       listen(sockfd,5);
       clength=sizeof(cli_addr);
       newsockfd=accept(sockfd,(struct sockaddr*)&cli_addr,&clength);
       printf("\nAccepted");
       do
       {
       printf("\n");
       recv(newsockfd,buffer,4096,0);
       choice=atoi(buffer);
       
       printf("\nClient message:%s",buffer);
       
      switch(choice)
      {
      
       case 1:strcpy(buffer,"enter file----->");
              send(newsockfd,buffer,4096,0);
       
              recv(newsockfd,buffer,4096,0);
              strcpy(content,"enter content--->");
              send(newsockfd,content,4096,0);
          
              recv(newsockfd,content,4096,0);
              fptr=fopen(buffer,"w");
              if(fptr==NULL)
              {
                 strcpy(buffer,"**** file creation unsuccessfull *******");
                 send(newsockfd,buffer,4096,0);
                 goto y;
               }
              fputs(content,fptr);
              strcpy(buffer,"**** file creation successfull *******");
              send(newsockfd,buffer,4096,0);
              y:printf("\n");
              fclose(fptr);
              break;

      
     case 2:strcpy(buffer,"enter file---->");
            send(newsockfd,buffer,4096,0);
         
            recv(newsockfd,buffer,4096,0);
            r=remove(buffer);
            if(r==0)
            {
            strcpy(buffer,"**********file removed************");
            send(newsockfd,buffer,4096,0);
            }
            else
            {
            strcpy(buffer,"**********file removal unsuccessfull************");
            send(newsockfd,buffer,4096,0);
            }
            break;

         

       
    case 3:strcpy(buffer,"enter file---->");
           send(newsockfd,buffer,4096,0);
         
           recv(newsockfd,buffer,4096,0);
           fptr=fopen(buffer,"r");
           if(fptr==NULL)
           {
           strcpy(buffer,"**** file opening unsuccessfull *******");
           send(newsockfd,buffer,4096,0);
           fclose(fptr);
           }
           else
           {
                while(fgets(buffer,4096,fptr)!=NULL)
                {
                   send(newsockfd,buffer,4096,0);
                }
                fclose(fptr);
                send(newsockfd,"*",4096,0);
           }
             
           break;
         
       
    case 4:strcpy(buffer,"enter file---->");
           send(newsockfd,buffer,4096,0);
        
           recv(newsockfd,buffer,4096,0);
           strcpy(content,"enter content to append--->");
           send(newsockfd,content,4096,0);
         
           recv(newsockfd,content,4096,0);
           fptr=fopen(buffer,"a");
           if(fptr==NULL)
           {
           strcpy(buffer,"**** file opening unsuccessfull *******");
           send(newsockfd,buffer,4096,0);
           goto z;
           }
           fputs(content,fptr);
           strcpy(buffer,"**** file appended successfully *******");
           send(newsockfd,buffer,4096,0);
           z:printf("\n");
           fclose(fptr);
           break;
         
     

   default:strcpy(buffer,"invalid input");
           send(newsockfd,buffer,4096,0);
           break;

      }
      
    }while(choice!=5);
    printf("\n");
    close(sockfd);
       
       
    return 0;
}
