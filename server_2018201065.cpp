//NAME:DHAWAL JAIN
//ROLL NUMBER:2018201065
#include <unistd.h> 
#include<iostream>
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#include<bits/stdc++.h>
#include<sys/stat.h>
#include<fcntl.h>
#include <sstream>
#include<thread>
//#define PORT 8888
#define BUFSIZE 512
using namespace std;
#include "sha_find.h"
#include "erase.h"
#include "erase1.h"
char buf[BUFSIZE]; 
//char *hello = "Hello from server"; 
void clear_buf()/////////////////////////////////BUFFER CLEAR TO AVOID OVERIDING////////////////////////////////
 {
    for(int i=0;i<BUFSIZE;i++)
        buf[i]='\0';
 }
void erase(int new_socket,string seed)/////////////////////CORRESPOND TO CLOSE ON CLIENT SIDE///////////////////////
 {
    
    int valread;
    valread = read( new_socket , buf, BUFSIZE); 
   // printf("%s\n",buf);
    ///////////READING PORT OF CLIENT WANT TO CLOSE/////////////////////////////////
    string s1;
    s1=buf;
    eraseFileLine(seed,s1);//FUNCTION OF erase.h
 }
 void rm_torrent(int new_socket,string seed)///////////////CORRESPOND TO REMOVE ON CLIENT SIDE/////////////////////////
 {
   // cout<<"hellooo"<<endl;
    int valread;
    valread = read( new_socket , buf, BUFSIZE); 
    //printf("%s\n",buf);
    //READING PORT AND FILENAME CORRESPONDING TO CLIENT AND FILE TO BE REMOVED
    string s1;
    s1=buf;
    memset(buf,'\0',sizeof(buf));
    valread = read( new_socket , buf, BUFSIZE); 
   // printf("%s\n",buf);
    string s2;
    s2=buf;
    eraseFile(seed,s1,s2);//Function of erase1.h////////////////////
 }
void share(int new_socket,string seed)//////////////////////CORRESPOND TO SHARE ON CLIENT SIDE I.e ENTRY IN SEEEDER FILE///////
{
    //int fd=open("log.txt",O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);
 int valread;
    string s=seed;
    int fd=open(s.c_str(),O_WRONLY|O_CREAT|O_APPEND, S_IRUSR|S_IWUSR);
      int count=0;
    while(1)
    {
     

            count++;
            //REACIVING ALL THE DETAILS REQUIRED TO STORE IN SEEDER LIST///////////////////////////////////
            valread = read( new_socket,buf, BUFSIZE); 
            if(buf[0]=='\0')
            {
                break;
            }
             int l=strlen((const char*)buf);
             write(fd,buf,l);
            // printf("%s\n",buf);
             char w[1];
             w[0]=' ';
             write(fd,w,1);
            if(count==1)
            { 
                char w1[1];
                 w1[0]='\n';
                 write(fd,w1,1);
            }
    }
           char w1[1];
                w1[0]='\n';
             write(fd,w1,1);
        close(fd);
       // cout<<"TREE"<<endl;
   }    
void foo(int new_socket,string seed) 
{ 
    int valread;
valread = read( new_socket , buf, BUFSIZE); 
    //
    //printf("%s\n",buf);
      // std::istringstream 
    int l=strlen((const char*)buf);
    //sha ki length
    std::ifstream file(seed.c_str());//////check
    char buf1[BUFSIZE];
    int i1;
    for(i1=0;i1<l;i1++)
        buf1[i1]=buf[i1];
       buf1[i1]='\0';
       memset(buf,'\0',sizeof(buf));
    std::string str; 
    int count=0;
    int j=0;
    //cout<<"hello start"<<endl;
    while (std::getline(file, str))
    {
       // cout<<"all"<<endl;
        //cout<<str<<endl;
        //cout<<"there"<<endl;
        count++;
        string t;
        if(count%2==1)//GETTING PARTICULAR LINE AS PER STANDARD SET IN SEEDER FILE
        t=str.substr(0,l);
       // cout<<t.c_str()<<" "<<(const char*)buf<<endl;
     if(strcmp(t.c_str(),(const char*)buf1)==0)
      {
        //cout<<"chup"<<endl;
       j=1;    
       continue;
      } 
    else if(j==1)
      {
        //cout<<"Are"<<endl;
        //cout<<str<<endl;
         istringstream iss(str);
        string word;
        while(iss >> word)
        {
        //printf("%s ",word.c_str());
            int i;
            for(i=0;i<word.length();i++)
         buf[i]=word[i];
          buf[i]='\0';
         send(new_socket ,buf, BUFSIZE , 0 );
         memset(buf,'\0',sizeof(buf));
        }
        j=0;
      }
      
    }
    memset(buf,'\0',sizeof(buf));
   send(new_socket ,buf, BUFSIZE , 0 );
    
}
void tracker1(string a,int PORT,string log)
{
      int server_fd, new_socket, valread; 
    struct sockaddr_in address; 
    int opt = 1; 
    int addrlen = sizeof(address); 
    char *sip_1;

             sip_1 = new char[a.length() + 1];
             strcpy(sip_1,a.c_str());
       
    // Creating socket file descriptor 
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    { 
        perror("socket failed"); 
        exit(EXIT_FAILURE); 
    } 
       
    // Forcefully attaching socket to the port 8080 
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, 
                                                  &opt, sizeof(opt))) 
    { 
        perror("setsockopt"); 
        exit(EXIT_FAILURE); 
    } 
    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = inet_addr(sip_1); 
    address.sin_port = htons( PORT ); 
       
    // Forcefully attaching socket to the port 8080 
    if (bind(server_fd, (struct sockaddr *)&address,  
                                 sizeof(address))<0) 
    { 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    } 
    if (listen(server_fd, 3) < 0)   
    { 
        perror("listen"); 
        exit(EXIT_FAILURE); 
    } 
     while(1)
     {
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address,  
                       (socklen_t*)&addrlen))<0) 
    { 
        perror("accept"); 
        exit(EXIT_FAILURE); 
    } 
      int valread;
      //char decide[BUFSIZE];
     valread = read( new_socket ,buf,BUFSIZE); 
     //isko bataya isko kya karna hai
    // cout<<"decide"<<endl;
    // cout<<buf[0]<<endl;
     if(buf[0]=='2')//GETTING INFORMED ABOUT ITS TASK
     {thread th1(foo,new_socket,log); 
        th1.join();
     }
    else if(buf[0]=='1')
    {thread th2(share,new_socket,log);
        th2.join();
    }
    else if(buf[0]=='3')
    {
       thread th3(erase,new_socket,log);
       th3.join();
    }
    else if(buf[0]=='4')
    {
        thread th4(rm_torrent,new_socket,log);
         th4.join();
    }
 
}
}

int main(int argc, char const *argv[]) 
{ 
       string ip1;
      string ip2;
      string  port1;
      string port2;
     // string client_ip = string(argv[1]);
    string server_ip1 = string(argv[1]);
    string server_ip2 = string(argv[2]);
    int i=0;
    int flag=0;
            while (server_ip1[i] != '\0')
            {
                if (server_ip1[i] == ':')
                    flag++;
                else if (flag == 0)
                {
                   ip1 += server_ip1[i];
                }
                else if (flag == 1)
                {
                    port1 += server_ip1[i];
                }
                i++;
            }
            i = 0;
            flag = 0;
            while (server_ip2[i] != '\0')
            {
                if (server_ip2[i] == ':')
                    flag++;
                else if (flag == 0)
                {
                    ip2 += server_ip2[i];
                }
                else if (flag == 1)
                {
                   port2 += server_ip2[i];
                }
                i++;
            }

      stringstream geek(port1); 
    int x = 0; 
    geek >> x; 
      //string port2=argv[4];
       stringstream geek1(port2); 
    int x1 = 0; 
    geek1 >> x1; 
      string s_seed=argv[3];
      string s_log=argv[4];
     //cout<<ip1<<" "<<x<<endl;
    
     thread th0(tracker1,ip1,x,s_seed); 
      th0.join();  
}
