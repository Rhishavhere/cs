#include<stdlib.h>
#include<stdio.h>
#define INF 999

int main(){
  int n, adj[20][20];

  printf("Enter No. Of Elements: ");
  scanf("%d",&n);

  printf("Enter Elements: ");
  for(int i=0;i<n;i++){
    for(int j =0;j<n;j++){
      scanf("%d",&adj[i][j]);

      if(i!=j && adj[i][j]==0){
        adj[i][j] = INF;
      }
    }
  }

  for(int k=0;k<n;k++){
    for(int i =0;i<n;i++){
      for(int j =0;j<n;j++){
        if(adj[i][j] > adj[i][k] + adj[k][j]){
          adj[i][j] = adj[i][k] + adj[k][j];
        }
      }
    }
  }

  printf("Shortest Path Matrix: \n");
  for(int i=0;i<n;i++){
    for(int j =0;j<n;j++){

      if(adj[i][j]==INF){
        printf("INF ");
      }
      else{
        printf("%d ",adj[i][j]);
      }
    }
    printf("\n");
  }
}