#include <stdio.h>   
#include <unistd.h>   
#include <fcntl.h>   
   
int main()   
{     int fd;      
char buffer[50];   
   
    /* open() – create and open a file */     fd = 
open("sample.txt", O_CREAT | O_RDWR, 0644);   
   
    if (fd < 0)   
    {   
        prin ("File opening failed\n");         
return 1;   
    }   
   
    /* write() – write data into file */     
write(fd, "Hello OS Lab", 12);   
   
    /* move file pointer to beginning */     
lseek(fd, 0, SEEK_SET);   
   
/* read() – read data from file */     
read(fd, buffer, 12);   
/* display data */     prin ("Data read from 
file: %s\n", buffer);   
/* close() – close the file */     
close(fd);   
return 0;   
}   
