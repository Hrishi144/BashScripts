#include<stdio.h>
void main(){
    float avgwaitingtime=0,avgturnaroundTime=0;
    int n,quantum;
    printf("Enetr the number of processes:");
    scanf("%d",&n);
    int bursttime[n],waitingTime[n],turnaroundtime[n],remainingtime[n];
    for(int i=0;i<n;i++){
        printf("Enter the burst time of process %d:",i+1);
        scanf("%d",&bursttime[i]);
        remainingtime[i]=bursttime[i];
        waitingTime[i]=0;
    }
    printf("Enter the time quantum: ");
    scanf("%d",&quantum);
    int time=0,done,gantttime[100],ganttindex=0,gantt[100];

    do{
        done=1;
        for(int i=0;i<n;i++){
            if (remainingtime[i]>0){
                done=0;
                gantt[ganttindex]=i;
                gantttime[ganttindex++]=time;
                if(remainingtime[i]>quantum){
                    time+=quantum;
                    remainingtime[i]-=quantum;
                }else{
                    time+=remainingtime[i];
                    waitingTime[i]=time-bursttime[i];
                    remainingtime[i]=0;
                }
            }
        }
    }while(!done);

    for(int i=0;i<n;i++){
        turnaroundtime[i]=bursttime[i]+waitingTime[i];
        avgwaitingtime+=waitingTime[i];
        avgturnaroundTime+=turnaroundtime[i];
    }

    printf("\nPROCESS ID\tBURST TIME\tWAITING TIME\tTURN AROUND TIME\n");
    for(int i=0;i<n;i++){
        printf("\np[%d]\t\t%d\t\t%d\t\t%d\n",i+1,bursttime[i],waitingTime[i],turnaroundtime[i]);
    }

    printf("\nAverage Waiting Time: %2f\n",avgwaitingtime/(float)n);
    printf("Average Turn Around Time: %2f\n",avgturnaroundTime/(float)n);

    printf("\t\tGANTT CHART\n\t");

    for(int i=0;i<ganttindex;i++){
        printf("--------");
    }

    printf("\n\t|");
    for(int i=0;i<ganttindex;i++){
        printf("  p[%d] |",gantt[i]+1);
    }

    printf("\n\t");

    for(int i=0;i<ganttindex;i++){
        printf("--------");
    }

    printf("\n\t");

    for(int i=0;i<ganttindex;i++){
        printf("%-8d",gantttime[i]);
    }
    printf("%d\n",time);
}
