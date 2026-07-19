#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
  int arr[1000], min, n, temp;
  clock_t start, end;
  double time_taken;

  printf("Enter the no. of elements: ");
  scanf("%d",&n);
  srand(time(NULL));
  for(int i =0;i<n;i++){
    arr[i]=rand() % 100;
  }
  printf("The Unsorted Array: ");
  for(int i =0;i<n;i++){
    printf("%d ",arr[i]);
  }

  start = clock();
  for(int i=0;i<n-1;i++){
    min = i;
    for(int j=i+1;j<n;j++){
      if(arr[j] < arr[min]){
        min = j;
      }
    }
    temp = arr[i];
    arr[i] =arr[min];
    arr[min] = temp;
  }
  end = clock();

  printf("\nThe Sorted Array: ");
  for(int i =0;i<n;i++){
    printf("%d ",arr[i]);
  }

  time_taken = (double)(end-start)/CLOCKS_PER_SEC;
  printf("\nTime Taken: %.10f",time_taken);
}