#include <stdio.h>  
int main()  
{  
    int pages[50], frames[10], time[10];  
    int n, f, i, j, k, flag, faults = 0, pos, min, counter = 0;  

    printf("Enter number of pages: ");  
    scanf("%d",&n);  

    printf("Enter page reference string:\n");  
    for(i=0;i<n;i++)  
        scanf("%d",&pages[i]);  

    printf("Enter number of frames: ");  
    scanf("%d",&f);  

    for(i=0;i<f;i++)  
        frames[i] = -1;  

    for(i=0;i<n;i++)  
    {  
        flag = 0;   // <-- FIXED here
        for(j=0;j<f;j++)  
        {  
            if(frames[j]==pages[i])  
            {  
                counter++;  
                time[j]=counter;  
                flag = 1;   // <-- FIXED here
                break;  
            }  
        }  
        if(flag==0)  
        {  
            if(i<f)  
            {  
                frames[i]=pages[i];  
                counter++;  
                time[i]=counter;  
                faults++;  
            }  
            else  
            {  
                min=time[0];  
                pos=0;  
                for(k=1;k<f;k++)  
                {  
                    if(time[k]<min)  
                    {  
                        min=time[k];  
                        pos=k;  
                    }  
                }  
                frames[pos]=pages[i];  
                counter++;  
                time[pos]=counter;  
                faults++;  
            }  
        }  
    }  
    printf("Total Page Faults = %d",faults);  
    return 0;  
}
