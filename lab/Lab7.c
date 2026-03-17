#include <stdio.h> 
#include <stdlib.h> 
// Function to calculate FCFS 
void fcfs(int arr[], int n, int head) { 
    int seek = 0; 
    for(int i = 0; i < n; i++) { 
        seek += abs(arr[i] - head); 
        head = arr[i]; 
    } 
    printf("FCFS Total Seek Time: %d\n", seek); 
} 
 
// Function to calculate SCAN 
void scan(int arr[], int n, int head, int size) { 
    int seek = 0, i, j; 
        // Sort array 
    for(i = 0; i < n-1; i++) { 
        for(j = 0; j < n-i-1; j++) { 
            if(arr[j] > arr[j+1]) { 
                int temp = arr[j]; 
                arr[j] = arr[j+1]; 
                arr[j+1] = temp; 
            } 
        } 
    } 
 
 
    // Move right 
    for(i = 0; i < n; i++) { 
        if(arr[i] >= head) { 
            seek += abs(arr[i] - head); 
            head = arr[i]; 
        } 
    } 
 
    // Move to end 
    seek += abs(size - 1 - head); 
    head = size - 1; 
    // Move left 
    for(i = n-1; i >= 0; i--) { 
        if(arr[i] < head) { 
            seek += abs(arr[i] - head); 
            head = arr[i]; 
        } 
    } 
 
    printf("SCAN Total Seek Time: %d\n", seek); 
} 
int main() { 
    int n, head, size; 
    printf("Enter number of requests: "); 
    scanf("%d", &n); 
    int arr[n]; 
    printf("Enter requests:\n"); 
    for(int i = 0; i < n; i++) { 
        scanf("%d", &arr[i]); 
    } 
    printf("Enter initial head position: "); 
    scanf("%d", &head); 
    printf("Enter disk size: "); 
    scanf("%d", &size); 
    fcfs(arr, n, head); 
    scan(arr, n, head, size); 
    return 0; 
} 
