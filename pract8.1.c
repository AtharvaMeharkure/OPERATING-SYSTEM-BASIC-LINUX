#include <stdio.h>

int main(){
    int n, i, completed=0, time=0;
    printf("Enter number of processes: "); scanf("%d",&n);

    int at[n], bt[n], pr[n], ct[n], tat[n], wt[n], rt[n];
    int remaining[n], visited[n];

    for(i=0;i<n;i++){
        printf("\nProcess %d\n", i+1);
        printf("Arrival Time: "); scanf("%d",&at[i]);
        printf("Burst Time: "); scanf("%d",&bt[i]);
        printf("Priority: "); scanf("%d",&pr[i]);
        remaining[i]=bt[i]; visited[i]=0;
    }

    while(completed<n){
        int pos=-1, highest=9999;
        for(i=0;i<n;i++){
            if(at[i]<=time && remaining[i]>0){
                if(pr[i]<highest){
                    highest=pr[i]; pos=i;
                }
            }
        }

        if(pos!=-1){
            if(visited[pos]==0){ rt[pos]=time-at[pos]; visited[pos]=1; }
            remaining[pos]--; time++;
            if(remaining[pos]==0){ completed++; ct[pos]=time; }
        } else time++;
    }

    float total_tat=0,total_wt=0,total_rt=0;
    for(i=0;i<n;i++){
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        total_tat+=tat[i]; total_wt+=wt[i]; total_rt+=rt[i];
    }

    printf("\nAT\tBT\tPR\tCT\tTAT\tWT\tRT\n");
    for(i=0;i<n;i++)
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", at[i],bt[i],pr[i],ct[i],tat[i],wt[i],rt[i]);

    printf("\nAverage TAT=%.2f, WT=%.2f, RT=%.2f\n", total_tat/n,total_wt/n,total_rt/n);
    return 0;
}
