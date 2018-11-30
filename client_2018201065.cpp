//NAME:DHAWAL JAIN
//ROLL NUMBER:2018201065
#include <unistd.h> 
#include<iostream>
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#include<arpa/inet.h>
#include<sys/stat.h>
#include<fcntl.h>
#include <type_traits>
#include <sstream>
#include <openssl/sha.h>
#include<thread>
#include<bits/stdc++.h>
using namespace std;
#include "sha_1.h"
#include "sha_find.h"
#define PORT1 8870
#define BUFSIZE 512
vector<string> load;
int port=8820;
int d=5;
char buf[BUFSIZE]; 
void clear_buf()
 {
    for(int i=0;i<BUFSIZE;i++)
        buf[i]='\0';
 }
 void erase(string s,int PORT,string tracker_ip)
 {
		 	struct sockaddr_in address; 
		    int sock = 0, valread; 
		    struct sockaddr_in serv_addr; 
		  //  char *hello = "abc"; 
		    char buffer[1024] = {0}; 
		    char *sip_1;

             sip_1 = new char[tracker_ip.length() + 1];
             strcpy(sip_1,tracker_ip.c_str());
		    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
		    { 
		        printf("\n Socket creation error \n"); 
		       // return -1; 
		    } 
		   
		    memset(&serv_addr, '0', sizeof(serv_addr)); 
		   
		    serv_addr.sin_family = AF_INET; 
		    serv_addr.sin_port = htons(PORT); 
		       
		    // Convert IPv4 and IPv6 addresses from text to binary form ////////////////////////////////////
		    if(inet_pton(AF_INET,sip_1, &serv_addr.sin_addr)<=0)  
		    { 
		        printf("\nInvalid address/ Address not supported \n"); 
		        //return -1; 
		    } 
		   
		    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
		    {   printf("\nConnection Failed \n"); 
		        //return -1; 
		    } 
		    buf[0]='3';
		    send( sock ,buf, BUFSIZE,0); 
		    char buf1[BUFSIZE];
		    int i;
		    for(i=0;i<s.length();i++)
		    	buf1[i]=s[i];
		    buf1[i]='\0';
		       send(sock , buf1 ,BUFSIZE, 0 ); 
 }
 void rm_torrent(int PORT,string port,string s1,string tracker_ip)
 {
		 	struct sockaddr_in address; 
		    int sock = 0, valread; 
		    struct sockaddr_in serv_addr; 
		  //  char *hello = "abc"; 
		    char buffer[1024] = {0}; 
		    char *sip_1;

             sip_1 = new char[tracker_ip.length() + 1];
             strcpy(sip_1,tracker_ip.c_str());
		    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
		    { 
		        printf("\n Socket creation error \n"); 
		       // return -1; 
		    } 
		   
		    memset(&serv_addr, '0', sizeof(serv_addr)); 
		   
		    serv_addr.sin_family = AF_INET; 
		    serv_addr.sin_port = htons(PORT); 
		       
		    // Convert IPv4 and IPv6 addresses from text to binary form /////////////////////////////////////////
		    if(inet_pton(AF_INET,sip_1, &serv_addr.sin_addr)<=0)  
		    { 
		        printf("\nInvalid address/ Address not supported \n"); 
		        //return -1; 
		    } 
		   
		    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
		    {   printf("\nConnection Failed \n"); 
		        //return -1; 
		    } 
		    buf[0]='4';
		    //INFORMING TRACKER ABOUT ITS TASK/////////////////////////////////////////////////////////////////////
		    send( sock ,buf, BUFSIZE,0); 
		    char buf1[BUFSIZE];
		    int i;
		    string z=port;
		    for(i=0;i<z.length();i++)
		    	buf1[i]=z[i];
		    buf1[i]='\0';
		       send(sock , buf1 ,BUFSIZE, 0 );
		       memset(buf1,'\0',sizeof(buf1));
		    for(i=0;i<s1.length();i++)
		    	buf1[i]=s1[i];
		    buf1[i]='\0'; 
            send(sock , buf1 ,BUFSIZE, 0 );
 }
 int  update_down(int PORT,string file_name,string upload_port,string client_ip,string tracker_ip)
 {
   struct sockaddr_in address; 
		    int sock = 0, valread; 
		    struct sockaddr_in serv_addr; 
		    //char *hello = "abc"; 
		    //char buffer[1024] = {0};
		     char *sip_1;

             sip_1 = new char[tracker_ip.length() + 1];
             strcpy(sip_1,tracker_ip.c_str()); 
		    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
		    { 
		        printf("\n Socket creation error \n"); 
		        return -1; 
		    } 
		   
		    memset(&serv_addr, '0', sizeof(serv_addr)); 
		   
		    serv_addr.sin_family = AF_INET; 
		    serv_addr.sin_port = htons(PORT); 
		       
		    // Convert IPv4 and IPv6 addresses from text to binary form 
		    if(inet_pton(AF_INET,sip_1, &serv_addr.sin_addr)<=0)  
		    { 
		        printf("\nInvalid address/ Address not supported \n"); 
		        return -1; 
		    } 
		    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
		    { 
		        printf("\nConnection Failed \n"); 
		        return -1; 
		    } 
		    
		    vector<string> v1;
		    int r=0;
		    int count=0;
		    buf[0]='1';
		    send( sock ,buf, BUFSIZE,0); 
		    string SHA=sha_search(file_name);//GETTING SHA OF DOWNLOADED FILE AGAIN TO STORE IT IN SEEDER LIST from sha_find

		             v1.push_back(SHA);
		             v1.push_back(upload_port);
		             v1.push_back(file_name);
		             v1.push_back(client_ip);
		             // for(int i=0;i<3;i++)
		             //    cout<<v1[i]<<" **** ";
		             for(int i=0;i<v1.size();i++)
		             {  
			             	int j;
			             	string s=v1[i];
			                for(j=0;j<s.length();j++)
			                    buf[j]=v1[i][j];
			                buf[j]='\0';
			                send(sock,buf,BUFSIZE,0);
			                //memset(buf,'\0',sizeof(buf));
			                clear_buf();
		               
		             }
		           // memset(buf,'\0',sizeof(buf));
		              send(sock,buf,BUFSIZE,0);
		            //  cout<<"TERRIFIC"<<endl;
		            //  clear_buf();
		           return 0;

}
 void client_down(int PORT,string file_name,string upload_port,int trac_port,string client_ip,string dest_path,string serv_ip,string tracker_ip)
{ 
	//////////////////////////////////////////HERE PORT OF SERVER REST MOSTLY TRACKER////////////////////////////////////////
	      //  cout<<"still not here"<<endl;
	/////////////////////////////////////////CENTRAL FUNCTION FOR DOWNLOAD TOGETHER WITH CLIENT_DOWN AND UPADATE_DOWN//////////
		    struct sockaddr_in address; 
		    int sock = 0, valread; 
		    struct sockaddr_in serv_addr; 
		    //char *hello = "abc"; 
		    char buffer[1024] = {0}; 
		    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
		    { 
		        printf("\n Socket creation error \n"); 
		       // return -1; 
		    } 
		     char *sip_1;

             sip_1 = new char[serv_ip.length() + 1];
             strcpy(sip_1,serv_ip.c_str());
		    memset(&serv_addr, '0', sizeof(serv_addr)); 
		   
		    serv_addr.sin_family = AF_INET; 
		    serv_addr.sin_port = htons(PORT); 
		       
		    // Convert IPv4 and IPv6 addresses from text to binary form 
		    if(inet_pton(AF_INET,sip_1, &serv_addr.sin_addr)<=0)  
		    { 
		        printf("\nInvalid address/ Address not supported \n"); 
		        //return -1; 
		    } 
		   
		    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
		    {   printf("\nConnection Failed \n"); 
		        //return -1; 
		    } 
		    char buf1[BUFSIZE];
		    int i;
		    //cout<<"Still there"<<endl;
		    for(i=0;i<file_name.length();i++)
		    	buf1[i]=file_name[i];
		    buf1[i]='\0';
		    send(sock , buf1 ,BUFSIZE, 0 ); 
		    string s;
		      //cout<<"ENTER THE NAME YOU WANT TO SAVE"<<endl; 
		      //cin>>s;
		      load.push_back(dest_path);
		    //  int fd=open(dest_path.c_str(),O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);
		    
	//   while(1)
    //   {
	//   int r=read(sock , buf, BUFSIZE);
	//  cout<<"r "<<r<<"buf "<<strlen(buf)<<"first "<<buf[0]<<endl;
	//   if(r<=0&&buf[0]=='\0'||strlen(buf)==0)
	//   	break; 
	//   write(fd,buf,BUFSIZE);
	  
	//   }
	ofstream createFile(dest_path, ofstream::binary);
	char *buffer1;
    long int n;
	do
    {
        buffer1 = new char[BUFSIZE];
        n = read(sock, buffer1, BUFSIZE);
        createFile.write(buffer1, n);
} while (n > 0);
			 // cout<<"DOWNLOADED "<<dest_path<<endl;
			  //UPADATING SEEDER LIST////////////////////////////////////////////////////////
		      update_down(trac_port,dest_path,upload_port,client_ip,tracker_ip);
} 
void client(int PORT,string tracker_ip)
{ 

		    struct sockaddr_in address; 
		    int sock = 0, valread; 
		    struct sockaddr_in serv_addr; 
		    //char *hello = "abc"; 
		    char buffer[1024] = {0}; 
		    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
		    { 
		        printf("\n Socket creation error \n"); 
		       // return -1; 
		    } 
		    char *sip_1;

             sip_1 = new char[tracker_ip.length() + 1];
             strcpy(sip_1,tracker_ip.c_str());
		    memset(&serv_addr, '0', sizeof(serv_addr)); 
		   
		    serv_addr.sin_family = AF_INET; 
		    serv_addr.sin_port = htons(PORT); 
		     
		    if(inet_pton(AF_INET,sip_1, &serv_addr.sin_addr)<=0)  
		    { 
		        printf("\nInvalid address/ Address not supported \n"); 
		        //return -1; 
		    } 
		   
		    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
		    {   printf("\nConnection Failed \n"); 
		        //return -1; 
		    } 
		    string s;
		     // cout<<"ENTER THE NAME YOU WANT TO SAVE"<<endl; 
		      //cin>>s;
		      load.push_back(s);
		     int fd=open(s.c_str(),O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);
      // fd=fileno(fp);
    //   while(1)
    //   {
	//   int r=read(sock , buf, BUFSIZE);
	//   //cout<<"r "<<r<<endl;
	//   if(r<=0&&buf[0]=='\0')
	//   	break; 
	//   write(fd,buf,BUFSIZE);
	  
	//   }

	
} 
int client_Test(int PORT,string file_name,string mt_name,string tracker1_ip,string tracker1_port,string tracker2_ip,string tracker2_port,string upload_port,string client_ip)
		{
			///////////CENTRAL FUNCTION FOR SHARE/////////////////////////////////////////////////////
		    struct sockaddr_in address; 
		    int sock = 0, valread; 
		    struct sockaddr_in serv_addr; 
		    char *sip_1;

             sip_1 = new char[tracker1_ip.length() + 1];
             strcpy(sip_1,tracker1_ip.c_str());
		    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
		    { 
		        printf("\n Socket creation error \n"); 
		        return -1; 
		    } 
		   
		    memset(&serv_addr, '0', sizeof(serv_addr)); 
		   
		    serv_addr.sin_family = AF_INET; 
		    serv_addr.sin_port = htons(PORT); 
		    if(inet_pton(AF_INET,sip_1, &serv_addr.sin_addr)<=0)  
		    { 
		        printf("\nInvalid address/ Address not supported \n"); 
		        return -1; 
		    } 
		    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
		    { 
		        printf("\nConnection Failed \n"); 
		        return -1; 
		    } 
		    vector<string> v1;
		    int r=0;
		    int count=0;
		    buf[0]='1';
		    send( sock ,buf, BUFSIZE,0); 
		    string SHA=sha_gen(tracker1_ip,tracker1_port,file_name,tracker2_ip,tracker2_port,mt_name);//GETTING SHA FROM Sha_1.h

		             v1.push_back(SHA);
		             v1.push_back(upload_port);
		             v1.push_back(file_name);
		             v1.push_back(client_ip);
		             for(int i=0;i<v1.size();i++)
		             {  
			             	int j;
			             	string s=v1[i];
			                for(j=0;j<s.length();j++)
			                    buf[j]=v1[i][j];
			                buf[j]='\0';
			                send(sock,buf,BUFSIZE,0);
			                clear_buf();
		               
		             }
		              send(sock,buf,BUFSIZE,0);
		           return 0;
}

void download(int PORT,string s,string upload_port,string client_ip,string dest_path,string tracker_ip)
		{
			//////////////////////////FIRST CALL IN CASE OF DOWNLOAD THAN CLIENT_DOWN AND THAN UPADATE DOWN////////////////////////
		    
            //cout<<"hello"<<endl;
		    int count=0;
		     struct sockaddr_in address; 
		    int sock = 0, valread; 
		    struct sockaddr_in serv_addr; 
		    //char *hello = "abc"; 
		    char *sip_1;

             sip_1 = new char[tracker_ip.length() + 1];
             strcpy(sip_1,tracker_ip.c_str());
		    int i;
		    string SHA=sha_search(s);
			cout<<SHA<<endl;
		    //char buffer[1024] = {0}; 
		    //cout<<SHA<<endl;
		    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
		    { 
		        printf("\n Socket creation error \n"); 
		        //return -1; 
		    } 
		   
		    memset(&serv_addr, '0', sizeof(serv_addr)); 
		   
		    serv_addr.sin_family = AF_INET; 
		    serv_addr.sin_port = htons(PORT); 
		       
		    // Convert IPv4 and IPv6 addresses from text to binary form 
		    if(inet_pton(AF_INET,sip_1, &serv_addr.sin_addr)<=0)  
		    { 
		        printf("\nInvalid address/ Address not supported \n"); 
		       // return -1; 
		    } 
		    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
		    { 
		        printf("\nConnection Failed \n"); 
		        //return -1; 
		    } 

		    buf[0]='2';//INFORMING TRACKER ABOUT ITS TASK
		    send( sock ,buf, BUFSIZE,0); 
		    for(i=0;i<SHA.length();i++)
		        buf[i]=SHA[i];
		    //buf[i]='\0';
		    send(sock ,buf, BUFSIZE , 0 ); 
			//sha bheja
		   // printf("Hello message sent\n"); 
		    vector<string> v;
		    //unordered_map<string,string> m;
		    int r=0;
		    count=0;
		    while(1)
		    {
		      //  cout<<"TO"<<endl;
		        count++;
		    valread = read(sock ,buf, BUFSIZE); 
		    //count++;
		    //cout<<valread<<endl;
		    if(buf[0]=='\0')
		        {
		            break; 
		        }
		      //  printf("r u\n");
		   // printf("%s\n",buf); 
		    string s4=buf;
		    clear_buf();
		    v.push_back(s4);
		    //cout<<"RUKJA"<<endl;
		    // if(count%2==0)
		    //    {
		    //    	  m[v[count-1]]=v[count-2];
		    //    }
		    }
		    //cout<<"map"<<endl;
		    //std::vector<std::thread> reader;
			cout<<count<<endl;
		    for(i=0;i<count-1;i++)
		    {
			   cout<<count<<endl;
		    	if(i%3==0)//BECAUSE THIS IS ORDER OF SEADER LIST FROM TRACKER///////////////////////////////////////
		    		{
		    			//cout<<v[i]<<endl;
		    			stringstream geek(v[i]); 
		                int x = 0; 
					    geek >> x; 
					    cout<<x<<endl;
					    //cout<<v[i+1]<<endl;
					    //cout<<"champ"<<endl;	
					    client_down(x,v[i+1],upload_port,PORT,client_ip,dest_path,v[i+2],tracker_ip);
		       
		    		}
		    }
		
        }

void server(int PORT,string a)
{
	//cout<<PORT<<endl;
	//////////////////////////////////////////////SERVER PART OF SAME CLIENT//////////////////////////////////////////
    int server_fd, new_socket, valread; 
    struct sockaddr_in address; 
    int opt = 1; 
    int addrlen = sizeof(address); 
    char *sip_1;

             sip_1 = new char[a.length() + 1];
             strcpy(sip_1,a.c_str());
    //char *hello = "Hello from server"; 
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    { 
        perror("socket failed"); 
        exit(EXIT_FAILURE); 
    } 
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, 
                                                  &opt, sizeof(opt))) 
    { 
        perror("setsockopt"); 
        exit(EXIT_FAILURE); 
    } 
    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = inet_addr(sip_1); 
    address.sin_port = htons( PORT ); 	
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
  
 
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address,  
                       (socklen_t*)&addrlen))<0) 
    { 
        perror("accept"); 
        exit(EXIT_FAILURE); 
    } 
    
	 int sum=0;
	 valread = read( new_socket , buf, BUFSIZE);
	 int fd;
	 string s;
	 s=buf;
	 cout<<s<<endl;
	 //cout<<s<<endl;
//  fd= open(s.c_str(),O_RDONLY,O_SYNC);
//  sleep(1);
//  int i;
//  int count=0;
//  for (;;) 
//  {
//         count++;
//         i = read(fd, buf, BUFSIZE);
//         //lseek(fd,BUFSIZE,SEEK_CUR);
//         cout<<"i "<<i<<endl;
//         send(new_socket,buf,BUFSIZE,0);
//         if (i < 512)
//             break;
//         //printf("%d\n",i);
        
        
//         //sum=sum+i;
// }
// clear_buf();
// send(new_socket,buf,BUFSIZE,0);
int flag=0;
ifstream readInputFile(s, ifstream::binary);
struct stat statObj;
stat(s.c_str(), &statObj);
long long int fsize = statObj.st_size; // Size of a file.
cout<<fsize<<endl;
    int chksz = BUFSIZE;
    //readInputFile.seekg(0, ios::beg);
    long int NC = fsize / chksz; // Calculate number of chunks.
    if (NC == 0)
    {
        NC = 1;
        chksz = fsize;
    }
    char *Buff;

    //  Send file from server to client.
    while (NC > 0)
    {
        Buff = new char[chksz];
        readInputFile.read(Buff, chksz);
        send(new_socket, Buff, chksz, 0);
        //logprinter(to_string(NC));
        NC--;
        if (NC == 0 && flag == 0)
        {
            flag = 1;
            long int t = fsize % chksz;
            if (t != 0)
            {
                NC = 1;
                chksz = t;
            }
        }
}
	
    } 

int main(int argc, char const *argv[])
{
   // cout<<"Want to start as server or client ....For server Enter S for client enter C"<<endl;
     //char k;
     //cin>>k;
    string s;
    string s1;
    string s5,s6,s7,s8,s9,s10;
    // s5;//tracker 1 ip
    // s6;//tracker 1 port
    // s7;//trecker 2 ip
    // s8;//tracker 2 port
    // s9=;//client port
    // s10//client ip
    string client_ip = string(argv[1]);
    string server_ip1 = string(argv[2]);
    string server_ip2 = string(argv[3]);
    int i=0;
    int flag=0;
    //EXTRACTING IP AND PORT SEPERATED BY : FOR ALL
    while (client_ip[i] != '\0')
            {
                if (client_ip[i] == ':')
                    flag++;
                else if (flag == 0)
                {
                    s10 +=client_ip[i];
                }
                else if (flag == 1)
                {
                    s9 +=client_ip[i];
                }
                i++;
            }
            i = 0;
            flag = 0;
            while (server_ip1[i] != '\0')
            {
                if (server_ip1[i] == ':')
                    flag++;
                else if (flag == 0)
                {
                   s5 += server_ip1[i];
                }
                else if (flag == 1)
                {
                    s6 += server_ip1[i];
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
                    s7 += server_ip2[i];
                }
                else if (flag == 1)
                {
                   s8 += server_ip2[i];
                }
                i++;
            }


//cout<<s10<<" "<<s9<<" "<<s5<<" "<<s6<<" "<<s7<<" "<<s8<<endl;
    //char k;
    //scanf("%c",&k);
    string  port1=s6;
    //cout<<port1<<endl;
    stringstream geek(port1); 
    int x = 0; 
    geek >> x; 
    //string port2=argv[1];
    string command;
    
    
    string logfile = string(argv[4]);
    ofstream outfile;
    outfile.open(logfile, fstream::out);
    outfile <<"Log file created in Client Machine"<< endl;
    //outfile.close();
    //logprinter("Log file created in Client Machine");
    string  port2=s9;
    // if(k=='C')
    //  {

    stringstream geek1(port2); 
    int y = 0; 
    geek1 >> y; 
       thread th2(server,y,s10);
       while(1)
        	{
        	
             string s = "";
            vector<string> commandVector;
            commandVector.clear();
        //cout<<"Enter Command"<<endl;
            getline(cin, command);
            //logprinter(command);
          int  i = 0;

           while (command[i] != '\0')
           {
            if (command[i] == ' ')
            {
                commandVector.push_back(s);
                s = "";
            }
            else
                s += command[i];
            i++;
           }
           commandVector.push_back(s);
            //printf("Press 6 For \n");
            //cin>>choice;
            if (commandVector[0] == "share")
            {
            	if (commandVector.size() != 3)
              {
                cout << "invalid share command" << endl;
                 outfile <<"Invalid share command"<< endl;
                continue;
              }
            //cout<<"Enter Filename and mtorrent name"<<endl;
            string s3,s4;
            //cin>>s3>>s4;
            s3=commandVector[1];
            s4=commandVector[2];
            thread th3(client_Test,x,s3,s4,s5,s6,s7,s8,s9,s10); 
            th3.join();
            outfile<<s4;
            outfile <<" has been shared"<< endl;
            cout<<"SUCCESS "<<s3<<endl;
            }
            else if(commandVector[0] == "get")
            {
               if (commandVector.size() != 3)
               {

                cout << "invalid get command" << endl;
                outfile <<"Invalid get command"<< endl;
                //logprinter("invalid share command");
                continue;
               }
                string t;
                t=commandVector[1];
            	std::string line,str;
                std::ifstream fin; 
                fin.open(t);
				int j=0;
				int count=0;
				int line1;
				char buf[512];
				while (std::getline(fin, str))
		        {
		        	//cout<<"IN THE HUT"<<endl;
		        	//cout<<str<<endl;
		             count++;
		             if(count==3)
		              line=str;
		        }      
		        fin.close();
		         string s6=line;
		         string destpath;
		         destpath=commandVector[2];
		         thread th4(download,x,s6,s9,s10,destpath,s5);
		         th4.join();
		         outfile<<destpath;
                 outfile <<" has been downloaded"<< endl;
                 cout<<"SUCCESS "<<destpath<<endl;
            }
            else if(commandVector[0] == "close")
            {
            	//cout<<"ENTER YOUR PORT"<<endl;
                string s11;
                //cin>>s5;
                s11=port2;
                thread th7(erase,s11,x,s5);
                th7.join();
              //  outfile<<s4;
               outfile<<"Connection Closed"<< endl;
               outfile<<"Bye"<<endl;
                break;
            }
            else if(commandVector[0] == "remove")
            {
            	if (commandVector.size() != 2)
                {
                cout << "invalid remove command" << endl;
                continue;
                }
            	 string t;
            	// cin>>t;
                t=commandVector[1];
            	std::string line,str;
               std::ifstream fin; 
                fin.open(t);
			    int j=0;
			    int count=0;
			    int line1;
			    char buf[512];
		       while (std::getline(fin, str))
              {
        	   //cout<<"IN THE HUT"<<endl;
        	   cout<<str<<endl;
               count++;
               if(count==3)
               line=str;
              }      
	            fin.close();
			    count=0; 
			    //cout<<"This is line"<<endl;
			    cout<<line<<endl;
			    thread th6(rm_torrent,x,port2,line,s5);
			    th6.join();
			    char *rmfile;
                rmfile = new char[commandVector[1].length() + 1];
                strcpy(rmfile, commandVector[1].c_str());
                remove(rmfile);
               outfile<<t;
               outfile<<" Has been unshared"<<endl;
               cout<<t<<" Removed"<<endl;
           }
	        else if(commandVector[0] == "show_downloads")
	        {
	        	cout<<"LIST OF DOWNLOADS IN CURRENT SESSION"<<endl;
	        	int i;
	        	for(i=0;i<load.size();i++)
	        		cout<<load[i]<<endl;
	        	 outfile<<"List of Download Accessed"<<endl;
	        }
    
    }
    outfile.close();
    
   
    //cout<<"mu"<<endl;
    //cout<<y<<endl;
    
    th2.join();
}
    
