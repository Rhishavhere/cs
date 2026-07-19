#include<stdio.h>
#include<stdlib.h>
#define INF 999

int main(){
  int n, cost[10][10];
  int visited[10] = {0};
  int min,v,u;
  int totalCost = 0, edges = 0; 

  printf("Enter No. Of Vertices: ");
  scanf("%d",&n);

  printf("\nEnter the Elements: ");
  for(int i=0;i<n;i++){
    for(int j =0;j<n;j++){
      scanf("%d", &cost[i][j]);

      if(cost[i][j]==0){
        cost[i][j]= INF;
      }
    }
  }

  visited[0] = 1;

  printf("\nEdges in MST: ");

  while(edges <n-1){
    min = INF;

    for(int i=0;i<n;i++){
      if(visited[i]){
        for(int j=0;j<n;j++){
          if(!visited[j] && cost[i][j] < min){
            min = cost[i][j];
            u = i;
            v = j;
          }
        }
      }
    }
    printf("%d -> %d : %d\n",u,v,min);
    totalCost += min;
    visited[v]=1;
    edges++;
  }
  printf("Total Cost MST : %d", totalCost);
  return 0;
}