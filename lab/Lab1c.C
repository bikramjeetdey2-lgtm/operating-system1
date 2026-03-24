#include<stdio.h>   
#include<unistd.h> 
#include<sys/types.h> void 
main()   
{   
prin ("\nBefore declaring FORK."); 
prin ("\nThe value of PID is : "); prin 
("\n%d",getpid()); prin ("\nThe  
value of PPID is : "); 
prin ("\n%d",getppid());   
pid_t pid=fork();//Used to create child process if(pid==0)//Child  
Process   
{   
prin ("\nA er declaring FORK."); prin 
("\nThe value of PID is zero."); prin 
("\nThe value of PID is : "); prin 
("\n%d",getpid()); prin ("\nThe  
value of PPID is : "); 
prin ("\n%d",getppid());   
}   
else if(pid>0)//Parent Process   
{   
prin ("\nA er declaring FORK."); prin ("\nThe 
value of PID is greater than zero."); prin ("\nThe 
value of PID is : "); prin ("\n%d",getpid()); prin 
("\nThe value of PPID is : "); prin 
("\n%d",getppid());   
}   
else//Error   
{   
prin ("\nA er declaring FORK."); prin ("\nThe 
value of PID is less than zero."); prin ("\nThe 
value of PID is : "); prin ("\n%d",getpid()); 
prin ("\nThe value of  
PPID is : "); prin ("%d",getppid());   
}   
}   
