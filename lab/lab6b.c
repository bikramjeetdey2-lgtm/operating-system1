#include <stdio.h>

int main() {
    int pages[50], frames[10];
    int n, f, i, j, k, flag, faults = 0;
    int pos, farthest, index;

    // Input: number of pages
    printf("Enter number of pages: ");
    scanf("%d", &n);

    // Input: page reference string
    printf("Enter page reference string:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    // Input: number of frames
    printf("Enter number of frames: ");
    scanf("%d", &f);

    // Initialize frames to empty (-1)
    for (i = 0; i < f; i++)
        frames[i] = -1;

    // Process each page in the reference string
    for (i = 0; i < n; i++) {
        flag = 0;

        // Check if page is already in a frame
        for (j = 0; j < f; j++) {
            if (frames[j] == pages[i]) {
                flag = 1;
                break;
            }
        }

        // If page not found (page fault)
        if (flag == 0) {
            if (i < f) {
                // Fill empty frame slots first
                frames[i] = pages[i];
                faults++;
            } else {
                // Find the page to replace (Optimal strategy)
                farthest = -1;

                for (j = 0; j < f; j++) {
                    index = -1;

                    // Look ahead in the reference string
                    for (k = i + 1; k < n; k++) {
                        if (frames[j] == pages[k]) {
                            index = k;
                            break;
                        }
                    }

                    // If a page is never used again, replace it
                    if (index == -1) {
                        pos = j;
                        break;
                    }

                    // Otherwise, replace the one used farthest in future
                    if (index > farthest) {
                        farthest = index;
                        pos = j;
                    }
                }

                frames[pos] = pages[i];
                faults++;
            }
        }
    }

    // Output total page faults
    printf("Total Page Faults = %d\n", faults);

    return 0;
}
