#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int partition(int A[], int low, int high){
  int pivot = A[low];
  int i = low+1;
  int j = high;

  while(1){
    while(i<=high && A[i]<=pivot){
      i++;
    }
    while(A[j]>pivot){
      j--;
    }

    if(i<j){
      int temp = A[i];
      A[i] = A[j];
      A[j] = temp;
    }
    else{
      break;
    }
  }

  int temp = A[low];
  A[low] = A[j];
  A[j] = temp;
  return j;
}

void quicksort(int A[], int low , int high){
  if(low < high){
    int pivot = partition(A,low,high);

    quicksort(A,low,pivot-1);
    quicksort(A,pivot+1, high);
  }
}

void main(){
  int n, A[1000];
  clock_t start,end;

  printf("\nEnter No. Of Elements: ");
  scanf("%d",&n);

  srand(time(NULL));
  for(int i=0;i<n;i++){
    A[i]=rand()%100;
  }

  printf("\nUnsorted Array: ");
  for(int i =0;i<n;i++){
    printf("%d ",A[i]);
  }

  start = clock();
  quicksort(A, 0, n-1);
  end = clock();

  printf("\nSorted Array: ");
  for(int i =0;i<n;i++){
    printf("%d ",A[i]);
  }

  double t = (double)(end-start)/CLOCKS_PER_SEC;
  printf("\nTime: %lf",t);

}