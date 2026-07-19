#include<stdlib.h>
#include<stdio.h>

int main(){
  int n, adj[20][20];

  printf("Enter No. Of Elements: ");
  scanf("%d",&n);

  printf("Enter Elements: ");
  for(int i=0;i<n;i++){
    for(int j =0;j<n;j++){
      scanf("%d",&adj[i][j]);
    }
  }

  for(int k=0;k<n;k++){
    for(int i =0;i<n;i++){
      for(int j =0;j<n;j++){
        adj[i][j] = adj[i][j] || ( adj[i][k] && adj[k][j]);
      }
    }
  }

  printf("Transitive Closure Matrix: \n");
  for(int i=0;i<n;i++){
    for(int j =0;j<n;j++){
      printf("%d ",adj[i][j]);
    }
    printf("\n");
  }
}