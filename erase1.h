#include <iostream>
#include <fstream>
using namespace std;
void eraseFile(std::string path, std::string eraseLine,std::string eraseLine2) {
std::string line,str;
std::ifstream fin;
fin.open(path);
std::ofstream temp; // contents of path must be copied to a temp file then renamed back to the path file
temp.open("temp.txt");
int j=0;
int count=0;
int line1;
char buf[512];
int f=0;
while (std::getline(fin, str))
    {
        count++;
        if(count%2==0)
        {
                 istringstream iss(str);
                
                string word;
                while(iss >> word)
                {
               
                        int i;
                        for(i=0;i<word.length();i++)
                             buf[i]=word[i];
                         buf[i]='\0';
                         string s2=buf;
                         if(s2==eraseLine)
                            {
                              //line1=count;
                              f=1;
                            }
                        if(f==1&&s2==eraseLine2)
                        {
                             line1=count;
                        }
                
                }
                j=0;
      }
    }
    fin.close();
    fin.open(path);
    count=0; 
while (getline(fin, line)) 
{
    count++;
    if (count==line1-1)
    {
    	j=1;
    continue;
    }
    if(j==1)
    {j=0;
    continue;
     }
        temp << line << std::endl;
}

temp.close();
fin.close();

const char * p = path.c_str(); // required conversion for remove and rename functions
remove(p);
rename("temp.txt", p);
}

