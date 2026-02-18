#include <stdio.h>

int main() {
    int n, tq;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], rt[n], wt[n], tat[n], response[n], at[n], ct[n];
    int i;

    for(i = 0; i < n; i++) {
        printf("Enter Arrival Time for P%d: ", i+1);
        scanf("%d", &at[i]);

        printf("Enter Burst Time for P%d: ", i+1);
        scanf("%d", &bt[i]);

        rt[i] = bt[i];
        response[i] = -1;
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    int time = 0, done;

    while(1) {
        done = 1;

        for(i = 0; i < n; i++) {
            if(at[i] <= time && rt[i] > 0) {
                done = 0;

                if(response[i] == -1)
                    response[i] = time - at[i];

                if(rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                } else {
                    time += rt[i];
                    ct[i] = time;
                    wt[i] = ct[i] - at[i] - bt[i];
                    rt[i] = 0;
                }
            }
        }

        if(done) {
            int all_done = 1;
            for(i = 0; i < n; i++) {
                if(rt[i] > 0) {
                    all_done = 0;
                    break;
                }
            }
            if(all_done)
                break;
            time++;
        }
    }

    float total_wt = 0, total_tat = 0, total_rt = 0;

    printf("\nProcess\tAT\tBT\tCT\tWT\tTAT\tRT\n");
    for(i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];

        total_wt += wt[i];
        total_tat += tat[i];
        total_rt += response[i];

        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1, at[i], bt[i], ct[i], wt[i], tat[i], response[i]);
    }

    printf("\nAverage Waiting Time = %.2f", total_wt/n);
    printf("\nAverage Turnaround Time = %.2f", total_tat/n);
    printf("\nAverage Response Time = %.2f\n", total_rt/n);

    return 0;
}

