#include <stdio.h>

struct Process {
    int pid;
    int at;   // Arrival Time
    int bt;   // Burst Time
    int pr;   // Priority
    int ct;   // Completion Time
    int tat;  // Turnaround Time
    int wt;   // Waiting Time
    int rt;   // Response Time
    int completed;
};

int main() {
    int n, i, time = 0, completed = 0;
    float total_tat = 0, total_wt = 0, total_rt = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for(i = 0; i < n; i++) {
        printf("\nProcess %d\n", i+1);
        p[i].pid = i+1;
        printf("Arrival Time: ");
        scanf("%d", &p[i].at);
        printf("Burst Time: ");
        scanf("%d", &p[i].bt);
        printf("Priority: ");
        scanf("%d", &p[i].pr);
        p[i].completed = 0;
    }

    while(completed < n) {
        int idx = -1;
        int highest_pr = 9999;

        for(i = 0; i < n; i++) {
            if(p[i].at <= time && p[i].completed == 0) {
                if(p[i].pr < highest_pr) {
                    highest_pr = p[i].pr;
                    idx = i;
                }
            }
        }

        if(idx != -1) {
            time += p[idx].bt;
            p[idx].ct = time;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
            p[idx].rt = p[idx].wt;  // Non-preemptive

            total_tat += p[idx].tat;
            total_wt += p[idx].wt;
            total_rt += p[idx].rt;

            p[idx].completed = 1;
            completed++;
        } else {
            time++;
        }
    }

    printf("\nPID\tAT\tBT\tPR\tCT\tTAT\tWT\tRT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].at, p[i].bt, p[i].pr,
               p[i].ct, p[i].tat, p[i].wt, p[i].rt);
    }

    printf("\nAverage Turnaround Time = %.2f", total_tat/n);
    printf("\nAverage Waiting Time = %.2f", total_wt/n);
    printf("\nAverage Response Time = %.2f\n", total_rt/n);

    return 0;
}
