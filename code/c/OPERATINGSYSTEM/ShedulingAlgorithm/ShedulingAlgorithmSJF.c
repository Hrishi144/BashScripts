                                                                                                             #include<stdio.h>
void main(){
       float averageWaitingtime=0,AvgturnaroundTime=0;
       int n;
    printf("Enter the number of processes:");   
       scanf("%d",&n);
       int bursttime[n],turnaroundtime[n],waitingtime[n],PID[n];
    for(int i=0;i<n;i++){
        printf("Enter the burst time of the process %d:",i+1);
        scanf("%d",&bursttime[i]);
        PID[i]=i+1;
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(bursttime[i]>bursttime[j]){
            int temp=bursttime[i];    
                bursttime[i]=bursttime[j];
                bursttime[j]=temp;

                temp=PID[i];
                PID[i]=PID[j];
                PID[j]=temp;
                
            }
        }
    }
        waitingtime[0]=0;
    for(int i=1;i<n;i++){
        waitingtime[i]=waitingtime[i-1]+bursttime[i-1];
        averageWaitingtime+=waitingtime[i];
    }
    for(int i=0;i<n;i++){
        turnaroundtime[i]=bursttime[i]+waitingtime[i];
        AvgturnaroundTime+=turnaroundtime[i];
    }
    printf("\nPROCESS ID\tBURST TIME\tWAITING TIME\tTURN AROUND TIME\n");
    for(int i=0;i<n;i++){
        printf("\np[%d]\t\t%d\t\t%d\t\t%d\n",PID[i],bursttime[i],waitingtime[i],turnaroundtime[i]);
    }
    printf("\n");
    printf("\nAverage Waiting Time: %2f\n",averageWaitingtime/(float)n);
    printf("\nAverage Turn Around Time: %2f\n",AvgturnaroundTime/(float)n);
    printf("\t\tGANTT CHART\n");
    printf("\t");
    for(int i=0;i<n;i++){
        printf("--------------");
    }
    printf("\n\t|");
    for(int i=0;i<n;i++){
        printf("    p[%d]|",PID[i]);
    }
    printf("\n\t");
    for(int i=0;i<n;i++){
        printf("--------------");
    }
    printf("\n\t0");
    int temp=0;
    for(int i=0;i<n;i++){
        temp+=bursttime[i];
        printf("   \t%d",temp);
    }
    printf("\n");
}