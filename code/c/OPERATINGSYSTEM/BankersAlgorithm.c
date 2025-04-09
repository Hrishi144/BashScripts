                                                                                                                                           #include <stdio.h>
                                                                                                                                           #include <stdlib.h>

void main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    int r;
    int visit[n];
    int a[n];
    
    printf("Enter the number of resources: ");
    scanf("%d", &r);
    
    int available[r], max[n][r], allocation[n][r], need[n][r];
    
    printf("Enter the available resources: ");
    for (int i = 0; i < r; i++) {
        scanf("%d", &available[i]);
    }

    for (int i = 0; i < n; i++) {
        visit[i] = 0;
        printf("Enter the max resources for process P%d: ", i + 1);
        for (int j = 0; j < r; j++) {
            scanf("%d", &max[i][j]);
        }
        printf("Enter the allocation for process P%d: ", i + 1);
        for (int j = 0; j < r; j++) {
            scanf("%d", &allocation[i][j]);
        }
        for (int j = 0; j < r; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    printf("\nPROCESS\tALLOCATION \tMAX  \tNEED\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t", i);
        for (int j = 0; j < r; j++) {
            printf("%d ", allocation[i][j]);
        }
        printf("  \t");
        for (int j = 0; j < r; j++) {
            printf("  %d ", max[i][j]);
        }
        printf("\t");
        for (int j = 0; j < r; j++) {
            printf(" %d ", need[i][j]);
        }
        printf("\n");
    }

    int c = 0, k = 0;
    while (c < n) {
        int flag = 0;
        for (int i = 0; i < n; i++) {
            int exec = 0;
            for (int j = 0; j < r; j++) {
                if (need[i][j] <= available[j]) {
                    exec++;
                }
            }
            if (exec == r && visit[i] == 0) {
                for (int j = 0; j < r; j++) {
                    available[j] += allocation[i][j];
                }
                flag = 1;
                visit[i] = 1;
                a[k++] = i;
                c++;
            }
        }
        if (flag == 0) {
            printf("\nNO SAFE SEQUENCE\n");
            exit(0);
        }
    }

    printf("\nSAFE SEQUENCE:\n< ");
    for (int i = 0; i < n; i++) {
        printf("P%d ", a[i]);
    }
    printf(">\n");
}
