#include<stdio.h>
#include<stdlib.h>

struct Item{
  int profit, weight;
  float ratio;
  int index;
};

int main(){
  int n, W;
  printf("Enter No. Of Items: ");
  scanf("%d",&n);

  struct Item item[n];

  printf("Enter Profits: ");
  for(int i=0;i<n;i++){
    scanf("%d",&item[i].profit);
  }

  printf("Enter Weights: ");
  for(int i=0;i<n;i++){
    scanf("%d",&item[i].weight);

    item[i].ratio = (float)item[i].profit/item[i].weight;
    item[i].index=i;
  }

  printf("Enter Capacity: ");
  scanf("%d",&W);

  for(int i=0;i<n-1;i++){
    for(int j =i+1;j<n;j++){
      if(item[i].profit < item[j].profit){
        struct Item temp = item[i];
        item[i]=item[j];
        item[j]=temp;
      }
    }
  }

  float profit = 0;
  float X[n];
  for(int i=0;i<n;i++){
    X[i]=0;
  }

  for(int i=0;i<n;i++){
    if(item[i].weight <= W){
      profit += item[i].profit;
      W -= item[i].weight;
      X[item[i].index] = 1.0;
    }
    else{
      X[item[i].index] = (float) W/item[i].weight;
      profit += item[i].ratio * W;
      break;
    }
  }

  printf("Maximum Profit = %.2f\n",profit);
  printf("Solution Vector X[] = ");
  for(int i=0;i<n;i++){
    printf("%.1f ", X[i]);
  }
}