#include<stdio.h>
#include<stdlib.h>
#define INF 999

int main(){
  int n, src, cost[20][20], dist[20], visited[20], min, u;

  printf("Enter No. Of Elements: ");
  scanf("%d",&n);

  printf("Enter Cost Matrix: ");
  for(int i=0;i<n;i++){
    for(int j =0;j<n;j++){
      scanf("%d",&cost[i][j]);

      if(i!=j && cost[i][j] == 0){
        cost[i][j] = INF;
      }
    }
  }

  printf("Enter Source Vertex: ");
  scanf("%d",&src);

  for(int i =0;i<n;i++){
    dist[i] = cost[src][i];
    visited[i]=0;
  }

  dist[src]=0;
  visited[src]=1;

  for(int i=0;i<n;i++){
    min = INF;

    for(int j=0;j<n;j++){
      if(!visited[j] && dist[j] < min){
        min = dist[j];
        u = j;
      }
    }

    visited[u]=1;

    for(int j =0;j<n;j++){
      if(!visited[j] && dist[j] > dist[u] + cost[u][j]){
        dist[j] = dist[u] + cost[u][j];
      }
    }
  }

  printf("Shorted Distances From Source: \n");
  for(int i=0;i<n;i++){
    printf("%d -> %d : %d\n",src,i,dist[i]);
  }

}