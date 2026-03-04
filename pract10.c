#include <stdio.h>

int main()
{
    int n, r, i, j, k;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resources: ");
    scanf("%d", &r);

    int alloc[n][r], max[n][r], avail[r];
    int need[n][r], finish[n], safeSeq[n];
    int count = 0;

    printf("\nEnter Allocation Matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < r; j++)
            scanf("%d", &alloc[i][j]);

    printf("\nEnter Maximum Matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < r; j++)
            scanf("%d", &max[i][j]);

    printf("\nEnter Available Resources:\n");
    for(i = 0; i < r; i++)
        scanf("%d", &avail[i]);

    for(i = 0; i < n; i++)
        finish[i] = 0;

    for(i = 0; i < n; i++)
        for(j = 0; j < r; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    for(k = 0; k < n; k++)
    {
        int found = 0;

        for(i = 0; i < n; i++)
        {
            if(finish[i] == 0)
            {
                int possible = 1;

                for(j = 0; j < r; j++)
                {
                    if(need[i][j] > avail[j])
                    {
                        possible = 0;
                        break;
                    }
                }

                if(possible)
                {
                    for(j = 0; j < r; j++)
                        avail[j] += alloc[i][j];

                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if(!found)
            break;
    }

    if(count == n)
    {
        printf("\nSystem is in SAFE state.\nSafe sequence:\n");
        for(i = 0; i < n - 1; i++)
            printf("P%d -> ", safeSeq[i]);
        printf("P%d\n", safeSeq[n - 1]);
    }
    else
    {
        printf("\nSystem is NOT in safe state.\n");
    }

    return 0;
}
