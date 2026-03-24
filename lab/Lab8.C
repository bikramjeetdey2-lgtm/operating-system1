#include <stdio.h> 
int main() { 
    int n, i, indexBlock; 
    int blocks[50]; 
    printf("Enter number of blocks in the file: "); 
    scanf("%d", &n); 
    printf("Enter the index block: "); 
    scanf("%d", &indexBlock); 
    printf("Enter the block numbers allocated for the file:\n"); 
    for(i = 0; i < n; i++) { 
        scanf("%d", &blocks[i]); 
    } 
    printf("\nFile Allocation Table (Indexed Allocation):\n"); 
    printf("Index Block: %d\n", indexBlock); 
    printf("Blocks allocated: "); 
    for(i = 0; i < n; i++) { 
        printf("%d ", blocks[i]); 
    } 
    printf("\n"); 
    return 0; 
}
