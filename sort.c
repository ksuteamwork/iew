#include<iostream>
#include<algorithm>
using namespace std;
void displayArray(int array[]);

int main()
{
  int arr[5]={31,25,42,33,75};
  displayArray(arr);

  sort(arr,arr+5);
  displayArray(arr);

  sort(arr,arr+5,greater<int>());
  displayArray(arr);

  return 0;
}
void displayArray(int array[])
{
  for(int i=0;i<5;i++)
    cout<<array[i]<<" ";
 
  cout<<endl;
}
