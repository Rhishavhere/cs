#include<stdio.h>
int main(){
    int n;
    int at[10],bt[10],ct[10],wt[10],tat[10],pr[10];
    int completed[10]={0};
    int time =0, done =0;

    printf("Enter number of Process : ");
    scanf("%d",&n);

    for(int i =0;i< n;i++){
        printf("Process %d AT : ",i+1);
        scanf("%d",&at[i]);
        printf("Process %d BT : ",i+1);
        scanf("%d",&bt[i]);
        printf("Process %d Priority : ",i+1);
        scanf("%d",&pr[i]);
        printf("\n");
    }

    while(done <n){
        int idx =-1;
        int highest_priority = 1000000;

        for(int i=0;i<n;i++){
            if(at[i] <=time && !completed[i]){
                if(pr[i]< highest_priority){
                    highest_priority = pr[i];
                    idx=i;
                }
            }
        }

        if(idx==-1){
            time++;
        }
        else{
            time+=bt[idx];
            ct[idx]=time;
            tat[idx]=ct[idx]-at[idx];
            wt[idx]=tat[idx]-bt[idx];
            completed[idx] =1;
            done++;
        }
    }

    printf("\nPID\tAT\tBT\tPR\tCT\tWT\tTAT\n");
    for(int i=0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", i+1,at[i],bt[i],pr[i],ct[i],wt[i],tat[i]);
    }
}
