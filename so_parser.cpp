#include <iostream>
#include <string>
#include <sys/types.h>
#include <bits/stdc++.h> 
#include <dirent.h>
#include <fstream>
#include <elf.h>
#include <string.h>
#include <map>
#include <unistd.h>

using namespace std;

int main(int argc, char *argv[])
{
   ifstream file;
   DIR * dir = NULL;
   string lib_path;
   unsigned int lib_count = 0;
   struct dirent * file_data = NULL;
   unsigned char elf_magic[4] = {0x7f, 0x45, 0x4c, 0x46};
   unsigned char buf[20];
   map<string, unsigned char> print_data;

   cout<<"enter the path:"<<endl;
   getline(cin, lib_path);

   dir = opendir(lib_path.c_str());
   if(dir != NULL)
   {
      chdir(lib_path.c_str());
      file_data = readdir(dir);
      while (file_data != NULL)
      {
         file.open(file_data->d_name);
         if(file)
         {
            file.read((char *)buf, sizeof(buf));
            if(!memcmp(elf_magic, buf, sizeof(elf_magic)))
            {
                if(buf[16] == ET_DYN)
                {
                   print_data.insert({file_data->d_name, buf[18]});
                   lib_count++;
                }
            }
            file.close();
         }
         file_data = readdir(dir);
      }

      closedir(dir);  
      cout<<"Total number of libraries:"<<lib_count<<"\n"<<endl;
      cout<<"File\t\t\t\t\tArchType\n";
      for(auto itr=print_data.begin(); itr != print_data.end(); ++itr)
         cout<<itr->first<<'\t'<<'\t'<<'\t'<<'\t'<<std::hex<<itr->second<<'\n';
   }
   else
   {
       perror("path: ");
   }

   return 0;
}