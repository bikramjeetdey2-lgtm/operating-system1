#include <stdio.h>   
#include <dirent.h>   
int main()   
{   
    DIR *d;     struct 
dirent *entry;   
   
    /* open current directory */     d 
= opendir(".");   
   
    if (d == NULL)   
    {   
        prin ("Directory cannot be opened\n");   
        return 1;   
    }   
    /* read directory entries */     prin 
("Directory contents:\n");     while  
((entry = readdir(d)) != NULL)   
    {   
        prin ("%s\n", entry->d_name);   
    }   
    /* close directory */     
closedir(d);     return  
0;   
}  
