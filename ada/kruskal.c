#include<stdio.h>
#include<stdlib.h>
#define  INF 999

int parent[20] = {0};

int find(int x){
  while(parent[x]!=x){
    x=parent[x];
  }
  return x;
}

int main(){
  int n, cost[20][20], edges=0,min,u,v, totalCost = 0;

  printf("Enter No. Of Elements: ");
  scanf("%d", &n);

  printf("Enter Elements: ");
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      scanf("%d",&cost[i][j]);
      if(i!=j && cost[i][j] == 0){
        cost[i][j]=INF;
      }
    }
  }

  for(int i = 0; i < n; i++)
    parent[i] = i;

  printf("Edges in MST: \n");
  while(edges < n-1){
    min=INF;
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if(cost[i][j]< min){
          min = cost[i][j];
          u = i;
          v= j;
        }
      }
    }

    int a = find(u);
    int b = find(v);

    if(a!=b){
      printf("%d -> %d : %d\n",u,v,min);
      totalCost += min;
      parent[b] = a;
      edges++;
    }
    cost[u][v]=cost[v][u]=INF;
  }
  printf("Total MST Cost: %d", totalCost);
  return 0;
}