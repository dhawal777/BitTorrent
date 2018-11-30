#include <unistd.h> 
#include<iostream>
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
//#include <string.h> 
#include<arpa/inet.h>
#include<sys/stat.h>
#include<fcntl.h>
#include <type_traits>
#include <sstream>
#include<thread>
#include<bits/stdc++.h>
#include <openssl/sha.h>
using namespace std;
#define BUFSIZE 512

string do_f(FILE *f);
string ptt(unsigned char *md,int sum);
#ifndef _OSD_POSIX
//int read(int, void *, unsigned int);
#endif
string sha_search(string file_name)
{
 // cout<<"hello sha"<<endl;
    //FILE *fp = fopen(mt_name.c_str(),"w");
    int i, err = 0;
    FILE *IN;
    
            IN = fopen(file_name.c_str(), "r");
             if (IN == NULL) {
               printf("JUMP");
             }
           
            string w=do_f(IN);
            
        
    return w;
    
}

string do_f(FILE *f)
{
    SHA_CTX c;
    unsigned char md[SHA_DIGEST_LENGTH];
    int fd;
    int i;
    unsigned char buf[BUFSIZE];
   // cout<<"3"<<endl;
    int sum=0;
    fd = fileno(f);
    SHA1_Init(&c);
    for (;;) {
        i = read(fd, buf, BUFSIZE);
        if (i <= 0)
            break;
        //printf("%d\n",i);
        sum=sum+i;
        SHA1_Update(&c, buf, (unsigned long)i);
    }
    SHA1_Final(&(md[0]), &c);
  
    fclose(f);
 string t=ptt(md,sum);
 return t;
}

string ptt(unsigned char *md,int sum)
{
    //FILE *fp;
    int i;
    //printf("%d\n",SHA_DIGEST_LENGTH);
     
 string s;
 char fhash[SHA_DIGEST_LENGTH*2];
    for (i = 0; i < SHA_DIGEST_LENGTH; i++)
        {
           
            //printf("%x\n",md[i]);
            //fprintf(fp,"%02x", md[i]);
          sprintf((char*)&(fhash[i*2]),"%02x",md[i]);
        }

    s=fhash;
   // cout<<s<<endl;
    return s;
}