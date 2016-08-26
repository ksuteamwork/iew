#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void com(int arr[], int data[], int start, int end, int index, int r){
  int j;
  if(index == r){
   for(j = 0; j < r; j++)
     printf("%d ",data[j]);
     printf("\n");
  }
  for(; start <= end && end - start +1 >= r-index; start++){
   data[index] = arr[start];
   com(arr, data, start+1, end, index+1, r);
  }
}
void print(int arr[], int n, int r){
  int data[r];
  com(arr, data, 0, n-1, 0, r);
}


int main(){
  int arr[] = {10, 20, 4, 2, 6, 33};
  int r, n = sizeof(arr)/sizeof(int);
  printf("Give me the number that you want to do = ");
  scanf("%d",&r);
  print(arr, n, r);
}
