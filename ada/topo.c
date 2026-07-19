#include<stdlib.h>
#include<stdio.h>

int main(){
  int n, adj[20][20];
  int indegree[20] = {0};
  int queue[20], front=0,rear=0;

  printf("Enter No. Of Elements: ");
  scanf("%d",&n);

  printf("Enter Elements: ");
  for(int i =0;i<n;i++){
    for(int j=0;j<n;j++){
      scanf("%d",&adj[i][j]);

      if(adj[i][j]==1){
        indegree[j]++;
      }
    }
  }

  for(int i =0;i<n;i++){
    if(indegree[i]==0){
      queue[rear++] = i;
    }
  }

  printf("Topological Order: ");
  while(front < rear){
    int u = queue[front++];
    printf("%d ",u);

    for(int v =0;v<n;v++){
      if(adj[u][v]==1){
        indegree[v]--;
        
        if(indegree[v]==0){
          queue[rear++] = v;
        }
      }
    }
  }

}