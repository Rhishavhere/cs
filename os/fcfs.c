#include<stdio.h>
int main(){
    int n;
    int at[19],bt[10],ct[10],wt[10],tat[10];

    printf("Enter Number of Processes : ");
    scanf("%d",&n);

    for(int i =0;i< n;i++){
        printf("Process %d AT : ",i+1);
        scanf("%d",&at[i]);

        printf("Process %d BT : ",i+1);
        scanf("%d",&bt[i]);
    }

    ct[0]=at[0]+bt[0];

    for(int i=1;i<n;i++){
        ct[i] = ct[i-1] + bt[i];
    }

    for(int i=0;i<n;i++){
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }
    int twt, ttat;
    for(int i=0;i<n;i++){
        ttat += tat[i];
        twt += wt[i];
    }

    printf("\nPID       AT      BT      CT      WT      TAT\n");
    for(int i=0;i<n;i++){
        printf("P%d     %d      %d      %d      %d      %d\n", i+1,at[i],bt[i],ct[i],wt[i],tat[i]);
    }
    printf("Avg TAT : %.2f\n",(float)ttat/n);
    printf("Avg WT : %.2f\n",(float)twt/n);
}
