#include<stdio.h>

struct memory{
    int size,alloc,index;
};
struct process{
    int psize,flag;
};
int main(){
    int numblock,limit,i,j;
    printf("\t\tBEST FIT\n");
    printf("Enter the number of memeory blocks:");
    scanf("%d",&numblock);

    struct memory m[numblock];
    printf("Enter the size of memory blocks:\n");
    for(i=0;i<numblock;i++){
        scanf("%d",&m[i].size);
        m[i].alloc=0;
        m[i].index=i+1;
    }
 for(i=0;i<numblock;i++){
    for(j=i+1;j<numblock;j++){
        if(m[i].size<m[j].size){
            struct memory temp=m[i];
            m[i]=m[j];
            m[j]=temp;
        }
    }
 }   
 printf("Enter the number of process:");
 scanf("%d",&limit);
 struct process p[limit];
 for(i=0;i<limit;i++){
    printf("Enter the size of process p%d:",i+1);
    scanf("%d",&p[i].psize);
    p[i].flag=0;
 }
 printf("\nPROCESS\t\tPROCESS SIZE\tBLOCK SIZE\t\tBLOCK NO.\n");
 printf("\n-----------------------------------------------------------");
 for(i=0;i<limit;i++){
    for(j=0;j<numblock;j++){
        if(p[i].flag==0 && p[i].psize<=m[j].size && m[j].alloc==0){
            p[i].flag=1;
            m[j].alloc=1;
           printf("\n\t%d\t\t%d\t\t%d\t\t%d\n",i+1,p[i].psize,m[j].size,m[j].index);
           break;
        }
    }
 }
 for(i=0;i<limit;i++){
    if(p[i].flag==0){
        printf("\nProcess %d of size %d is not allocated",i,p[i].psize);
    }
 }
 return 0;
}