#include<stdio.h> 
void firstFit(int blockSize[], int m, int processSize[], int n) 
{ 
int alloca on[n]; 
    for(int i=0;i<n;i++) 
        alloca on[i]=-1; 
 
    for(int i=0;i<n;i++) 
    { 
        for(int j=0;j<m;j++) 
        { 
            if(blockSize[j] >= processSize[i]) 
            { 
                alloca on[i] = j; 
                blockSize[j] -= processSize[i]; 
                break; 
            } 
        } 
    } 
 
    prin ("\nFIRST FIT\nProcess No.\tProcess Size\tBlock No.\n"); 
    for(int i=0;i<n;i++) 
    { 
        if(alloca on[i]!=-1) 
            prin ("%d\t\t%d\t\t%d\n",i+1,processSize[i],alloca on[i]+1); 
        else 
            prin ("%d\t\t%d\t\tNot Allocated\n",i+1,processSize[i]); 
    } 
} 
 
void bestFit(int blockSize[], int m, int processSize[], int n) 
{ 
    int alloca on[n]; 
    for(int i=0;i<n;i++) 
        alloca on[i]=-1; 
 
    for(int i=0;i<n;i++) 
    { 
        int bestIdx=-1; 
        for(int j=0;j<m;j++) 
        { 
            if(blockSize[j]>=processSize[i]) 
            { 
                if(bestIdx==-1 || blockSize[j]<blockSize[bestIdx]) 
                    bestIdx=j; 
            } 
        } 
 
        if(bestIdx!=-1) 
        { 
            alloca on[i]=bestIdx; 
            blockSize[bestIdx]-=processSize[i]; 
        } 
    } 
 
    prin ("\nBEST FIT\nProcess No.\tProcess Size\tBlock No.\n"); 
    for(int i=0;i<n;i++) 
    { 
        if(alloca on[i]!=-1) 
            printf("%d\t\t%d\t\t%d\n", i+1, processSize[i], allocation[i] + 1); 
        else 
            prin ("%d\t\t%d\t\tNot Allocated\n",i+1,processSize[i]); 
    } 
} 
 
int main() 
{ 
    int blockSize[] = {100, 500, 200, 300, 600}; 
    int processSize[] = {212, 417, 112, 426}; 
 
    int m = 5; 
    int n = 4; 
 
    int block1[5], block2[5]; 
    for(int i=0;i<m;i++) 
    { 
        block1[i]=blockSize[i]; 
        block2[i]=blockSize[i]; 
    } 
 
    firstFit(block1,m,processSize,n); 
    bestFit(block2,m,processSize,n); 
 
    return 0; 
}
