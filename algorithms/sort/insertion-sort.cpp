#include <iostream>

using namespace std;

int main(){

  int arr[10] = {10,8,6,4,3,7,2,1,9};

  // insertion sort implementation
  // time complexity -> O(n^2) for worst case
  // time complexity -> O(n) for best case
  int i,j;
  for(i=1;i<10;i++){
    int key = arr[i];
    j = i-1;
    while(j>=0 && arr[j] > key){
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = key;
  }

  for(i=0;i<10;i++){
    cout << arr[i] << '\n';
  }

  return 0;
}