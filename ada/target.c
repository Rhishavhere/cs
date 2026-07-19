#include<stdlib.h>
#include<stdio.h>

int n, target;
int set[20],x[20];

void subset(int sum, int k){
  if(sum == target){
    printf("Subset : ");
    for(int i=0;i<n;i++){
      if(x[i]==1){
        printf("%d ",set[i]);
      }
    }
    printf("\n");
    return;
  }

  for(int i=k;i<n;i++){
    if(sum + set[i] <= target){
      x[i]=1;
      subset(sum+set[i], i+1);
      x[i]=0;
    }
  }
}


int main(){
  printf("Enter No. Of Elements: ");
  scanf("%d",&n);
  printf("Enter The Elements: ");
  for(int i=0;i<n;i++){
    scanf("%d",&set[i]);
  }
  printf("Enter Target: ");
  scanf("%d",&target);

  printf("Possible Target-Sum Subsets are: \n");
  subset(0,0);
}