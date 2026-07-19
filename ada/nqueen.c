#include<stdlib.h>
#include<stdio.h>

int x[10];

int place(int row){
  for(int i=1;i< row;i++){
    if(x[i]==x[row] || abs(x[i]-x[row]) == abs(i-row)){
      return 0;
    }
  }
  return 1;
}

void solve(int n){
  int row = 1;
  x[row]=0;

  while(row > 0){
    x[row]++;

    while(x[row] <= n && !place(row)){
      x[row]++;
    }

    if(x[row]<=n){
      if(row == n){
        return;
      }

      row++;
      x[row]=0;
    }
    else{
      row--;
    }
  }
}

int main(){
  int n;
  printf("Enter No. Of Queens: ");
  scanf("%d", &n);

  solve(n);

  printf("Queen Positions: \n");
  for(int i=1;i<=n;i++){
    printf("Queen %d -> Row %d | Column %d\n", i,i,x[i]);
  }
}