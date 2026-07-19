#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void merge(int B[], int p, int C[], int q, int A[]){
  int i=0,j=0,k=0;

  while(i<p && j<q){
    if(B[i] <= C[j]){
      A[k++] = B[i++];
    }else{
      A[k++] = C[j++];
    }
  }

  while(i<p){
    A[k++] = B[i++];
  }
  while(j<q){
    A[k++] = C[j++];
  }
}


void mergeSort(int A[], int n){
  if(n>1){
    int mid = n/2;
    int B[1000], C[1000];

    for(int i=0;i<mid;i++){
      B[i] = A[i];
    }

    for(int i =mid;i<n;i++){
      C[i-mid]=A[i];
    }

    mergeSort(B, mid);
    mergeSort(C, n-mid);
    merge(B,mid,C,n-mid,A);

  }
}



int main(){
  int n, A[1000];
  clock_t start, end;

  printf("Enter No. of Elements: ");
  scanf("%d",&n);

  srand(time(NULL));

  for(int i=0;i<n;i++){
    A[i]=rand() % 100;
  }

  printf("\nUnsorted Array: ");
  for(int i=0;i<n;i++){
    printf("%d ",A[i]);
  }

  start = clock();
  mergeSort(A,n);
  end = clock();

  double t = (double)(end-start)/CLOCKS_PER_SEC;

  printf("\nSorted Array: ");
  for(int i=0;i<n;i++){
    printf("%d ",A[i]);
  }

  printf("\nTime Elapsed: %.10f",t);
}