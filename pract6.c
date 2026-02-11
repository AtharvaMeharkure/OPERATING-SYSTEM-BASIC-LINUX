//SJF
#include <stdio.h>

struct Process {
    int pid;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

int main() {
    int n, i, j;
    struct Process p[20], temp;

    float total_waiting = 0, total_turnaround = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &p[i].burst_time);
        p[i].pid = i + 1;
    }

    // Sort processes by burst time (SJF)
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(p[i].burst_time > p[j].burst_time) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    // Calculate waiting time
    p[0].waiting_time = 0;
    for(i = 1; i < n; i++) {
        p[i].waiting_time = p[i-1].waiting_time + p[i-1].burst_time;
    }

    // Calculate turnaround time
    for(i = 0; i < n; i++) {
        p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;
        total_waiting += p[i].waiting_time;
        total_turnaround += p[i].turnaround_time;
    }

    printf("\nPID\tBurst\tWaiting\tTurnaround\n");
    for(i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\n", 
               p[i].pid, 
               p[i].burst_time, 
               p[i].waiting_time, 
               p[i].turnaround_time);
    }

    printf("\nAverage Waiting Time: %.2f", total_waiting / n);
    printf("\nAverage Turnaround Time: %.2f\n", total_turnaround / n);

    return 0;
}
