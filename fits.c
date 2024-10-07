#include<stdio.h>
void bestfit(int size[], int m, int process[], int n) {
    int alloc[n];
    for (int i = 0; i < n; i++) {
        alloc[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        int best = -1;
        for (int j = 0; j < m; j++) {
            if (size[j] >= process[i]) {
                if (best == -1 || size[best] > size[j]) {
                    best = j;
                }
            }
        }
        if (best != -1) {
            alloc[i] = best;
            size[best] -= process[i];
        }
    }
    printf("\nBest Fit Allocation:\n");
    printf("Pro.No\tPro.Size\tBlk.No\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i + 1, process[i]);
        if (alloc[i] != -1) {
            printf("%d", alloc[i] + 1);
        } else {
            printf("Not allocated");
        }
        printf("\n");
    }
}
void worstfit(int size[], int m, int process[], int n) {
    int alloc[n];
    for (int i = 0; i < n; i++) {
        alloc[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        int wrst = -1;
        for (int j = 0; j < m; j++) {
            if (size[j] >= process[i]) {
                if (wrst == -1 || size[wrst] < size[j]) {
                    wrst = j;
                }
            }
        }
        if (wrst != -1) {
            alloc[i] = wrst;
            size[wrst] -= process[i];
        }
    }
    printf("\nWorst Fit Allocation:\n");
    printf("Pro.No\tPro.Size\tBlk.No\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i + 1, process[i]);
        if (alloc[i] != -1) {
            printf("%d", alloc[i] + 1);
        } else {
            printf("Not allocated");
        }
        printf("\n");
    }
}

// Function for First Fit
void firstfit(int size[], int m, int process[], int n) {
    int alloc[n];
    for (int i = 0; i < n; i++) {
        alloc[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (size[j] >= process[i]) {
                alloc[i] = j;
                size[j] -= process[i];
                break;
            }
        }
    }
    printf("\nFirst Fit Allocation:\n");
    printf("Pro.No\tPro.Size\tBlk.No\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i + 1, process[i]);
        if (alloc[i] != -1) {
            printf("%d", alloc[i] + 1);
        } else {
            printf("Not allocated");
        }
        printf("\n");
    }
}
int main() {
    int m = 5;
    int n = 4;
    int size[] = {300, 50, 100, 250, 420};
    int process[] = {299, 25, 110, 300};
    int choice;
    printf("Choose Memory Allocation Algorithm:\n");
    printf("1. Best Fit\n2. Worst Fit\n3. First Fit\nEnter your choice: ");
    scanf("%d", &choice);
    int sizeCopy[m];
    for (int i = 0; i < m; i++) {
        sizeCopy[i] = size[i];
    }
    
    switch (choice) {
        case 1:
            bestfit(sizeCopy, m, process, n);
            break;
        case 2:
            worstfit(sizeCopy, m, process, n);
            break;
        case 3:
            firstfit(sizeCopy, m, process, n);
            break;
        default:
            printf("Invalid choice!\n");
    }
    
    return 0;
}
