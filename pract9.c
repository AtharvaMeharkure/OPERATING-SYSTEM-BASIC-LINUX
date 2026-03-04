#include <stdio.h>
#include <limits.h>

struct Process {
    int id, at, bt, remaining_bt, ct, tat, wt;
};

int main() {
    int n, completed = 0, current_time = 0;
    float total_tat = 0, total_wt = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);
    struct Process p[n];

    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Enter Arrival Time and Burst Time for P%d: ", p[i].id);
        scanf("%d %d", &p[i].at, &p[i].bt);
        p[i].remaining_bt = p[i].bt;
    }

    while (completed != n) {
        int idx = -1;
        int max_bt = -1;

        // Find process with max remaining time among arrived processes
        for (int i = 0; i < n; i++) {
            if (p[i].at <= current_time && p[i].remaining_bt > 0) {
                if (p[i].remaining_bt > max_bt) {
                    max_bt = p[i].remaining_bt;
                    idx = i;
                }
                // Tie-breaker: Smaller arrival time (FCFS)
                else if (p[i].remaining_bt == max_bt) {
                    if (p[i].at < p[idx].at) {
                        idx = i;
                    }
                }
            }
        }

        if (idx != -1) {
            p[idx].remaining_bt--;
            current_time++;
            
            if (p[idx].remaining_bt == 0) {
                p[idx].ct = current_time;
                p[idx].tat = p[idx].ct - p[idx].at;
                p[idx].wt = p[idx].tat - p[idx].bt;
                total_tat += p[idx].tat;
                total_wt += p[idx].wt;
                completed++;
            }
        } else {
            current_time++; // CPU is idle
        }
    }

    printf("\nID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }

    printf("\nAverage Turnaround Time: %.2f", total_tat / n);
    printf("\nAverage Waiting Time: %.2f\n", total_wt / n);

    return 0;
}

