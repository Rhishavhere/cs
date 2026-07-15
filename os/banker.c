#include<stdio.h>

int main(){
    int n,m;
    int i,j;

    printf("Enter Number Of Processes and Resources: ");
    scanf("%d %d",&n,&m);

    int max[n][m], alloc[n][m], need[n][m], avail[m], work[m], finish[n], total[m];

    printf("Enter Max Matrix : ");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&max[i][j]);
        }
    }

    printf("Enter Allocation Matrix : ");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&alloc[i][j]);
        }
    }

    printf("Enter Resources Vector: ");
    for(i=0;i<m;i++){
        scanf("%d",&total[i]);
    }

    for(j=0;j<m;j++){
            int sum = 0;
            for(i=0;i<n;i++){
                sum += alloc[i][j];
            }
            avail[j] = total[j] - sum;
        }
    
    for(i=0;i<n;i++){
        finish[i]=0;
        for(j=0;j<m;j++){
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }

    for(i=0;i<m;i++){
        work[i] = avail[i];
    }

    printf("Safe Sequence Check: ");

    int count=0;
    while(count < n){
        int found = 0;
        for(i=0;i<n;i++){
            if(finish[i]==0){
                int canAllocate =1;
                for(j=0;j<m;j++){
                    if(need[i][j] > work[j]){
                        canAllocate=0;
                        break;
                    }
                }
                if(canAllocate){
                    printf("Process P%d Executed\n",i);
                    for(j=0;j<m;j++){
                        work[j]+=alloc[i][j];
                    }
                    printf("Available Resources:");
                    for(int k=0;k<m;k++)
                        printf("%d ",work[k]);
                    finish[i]=1;
                    found =1;
                    count++;
                }
            }
        }
        if(!found){
            printf("System is not safe state\n");
            return 0;
        }
    }
    printf("System is safe state\n");
    return 0;
}
