#include<stdio.h>

int max(int a, int b){
  return (a>b)?a:b;
}

int main(){
  int n, cap;
  
  printf("Enter No. Of Items: ");
  scanf("%d",&n);

  int profit[n], weight[n];

  printf("Enter Profits: ");
  for(int i=0;i<n;i++){
    scanf("%d", &profit[i]);
  }

  printf("Enter Weights: ");
  for(int i=0;i<n;i++){
    scanf("%d", &weight[i]);
  }

  printf("Enter Capacity: ");
  scanf("%d", &cap);

  int dp[n+1][cap+1];

  for(int i =0; i<=n; i++){
    for(int w=0; w<=cap; w++){
      if(i==0 || w == 0){
        dp[i][w] = 0;
      }
      else if( weight[i-1] <= w){
        dp[i][w] = max(
          dp[i-1][w],
          profit[i-1] + dp[i-1][w-weight[i-1]]
        );
      }
      else{
        dp[i][w] = dp[i-1][w];
      }
    }
  }
  
  printf("\nMaximum Profit = %d\n", dp[n][cap]);
  
  //Solution Vector

  int X[n];
  for(int i=0;i<n;i++)
    X[i]=0;

  int result = dp[n][cap];

  for(int i=n; i>0; i--){
    if(result != dp[i-1][cap]){
      X[i-1] = 1;
      result -= profit[i-1];
      cap -= weight[i-1];
    }
  }

  printf("Solution Vector X[] = ");
  for(int i=0;i<n;i++)
    printf("%d ", X[i]);

}