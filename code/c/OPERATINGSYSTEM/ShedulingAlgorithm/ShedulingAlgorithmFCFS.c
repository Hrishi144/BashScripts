                                                                                             #include<stdio.h>
void main(){
    float avgWaitingTime=0,avgturnaroundtime=0;
    int n;
    printf("Enter the number of processes:");
    scanf("%d",&n);
    int bursttime[n],waitingtime[n],turnaroundtime[n];
    for(int i=0;i<n;i++){
        printf("Enter the burst time of process %d:",i+1);
        scanf("%d",&bursttime[i]);
    }waitingtime[0]=0;
    for(int i=1;i<n;i++){
        waitingtime[i]=waitingtime[i-1]+bursttime[i-1];
        avgWaitingTime+=waitingtime[i];
    }
    for(int i=0;i<n;i++){
        turnaroundtime[i]=bursttime[i]+waitingtime[i];
        avgturnaroundtime+=turnaroundtime[i];
    }
    printf("\nPROCESS ID\tBURST TIME\tWAITING TIME\tTURN AROUND TIME\n");
    for(int i=0;i<n;i++){
        printf("\np[%d]\t\t%d\t\t%d\t\t%d",i+1,bursttime[i],waitingtime[i],turnaroundtime[i]);
    }
    printf("\n");
    printf("\nAverage waiting time: %2f\n",avgWaitingTime/(float)n);
    printf("\nAverage Turn around time: %2f\n",avgturnaroundtime/(float)n);


    printf("\t\tGANTT CHART\n");
    printf("\t");
    for(int i=0;i<n;i++){
          printf("------------");
    }
    printf("\n\t|");
    for(int i=0;i<n;i++){
             printf("   p[%d]|",i+1);
    }
    printf("\n\t");
    for(int i=0;i<n;i++){
        printf("--------------");
    }
    printf("\n\t0");
    int temp=0;
    for(int i=0;i<n;i++){
        temp+=bursttime[i];
        printf("\t%d",temp);

    }
    printf("\n");
}