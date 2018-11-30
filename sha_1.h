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

string do_fp(FILE *f,FILE *fp);
string pt(unsigned char *md,int sum,FILE *fp);
#ifndef _OSD_POSIX
//int read(int, void *, unsigned int);
#endif
string sha_gen(string tracker1_ip,string tracker1_port,string file_name,string tracker2_ip,string tracker2_port,string mt_name)
{
    FILE *fp = fopen(mt_name.c_str(),"w");
    int i, err = 0;
    FILE *IN;
    //string s1="TRACKER URL1";
    //string s2="TRACKER URL2";
   // fprintf(fp,"%s",s1)
    //cout<<"1"<<endl;
    fprintf(fp,"TRACKER URL1:%s %s\n",tracker1_ip.c_str(),tracker1_port.c_str());
   // fprintf(fp,"\n%s",s2);
    fprintf(fp,"TRACKER URL2:%s %s",tracker2_ip.c_str(),tracker2_port.c_str());
    fprintf(fp,"\n%s\n",file_name.c_str());
    //fprintf()
  //cout<<"2"<<endl;
            IN = fopen(file_name.c_str(), "r");
             if (IN == NULL) {
               printf("JUMP");
               //continue;
             }
           // printf("SHA1(%s)= ",file_name);
            string w=do_fp(IN,fp);
            //fclose(IN);
        
    return w;
    //exit(err);
}


string do_fp(FILE *f,FILE *fp)
{
    SHA_CTX c;
    unsigned char md[SHA_DIGEST_LENGTH];
    int fd;
    int i;
    unsigned char buf[BUFSIZE];
    //cout<<"3"<<endl;
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
    string t=pt(md,sum,fp);
// fclose(fp);
    return t;
}

string pt(unsigned char *md,int sum,FILE *fp)
{
    //FILE *fp;
    int i;
    //printf("%d\n",SHA_DIGEST_LENGTH);
     char fhash[SHA_DIGEST_LENGTH*2];
 string s;
    for (i = 0; i < SHA_DIGEST_LENGTH; i++)
        {
            //s=s+to_string(md[i]);
            //printf("%x\n",md[i]);
            fprintf(fp,"%02x", md[i]);
            sprintf((char*)&(fhash[i*2]),"%02x",md[i]);
        }
       // string s(md, md + sizeof md/ sizeof md[0] );
    fprintf(fp,"\n%d\n",sum);
   // printf("\n");
    fclose(fp);
    s=fhash;
//(const char*)md.to_string;
    //cout<<s<<endl;
    return s;
}