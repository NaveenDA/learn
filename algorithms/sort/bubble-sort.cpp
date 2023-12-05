#include <iostream>

int main(){

  int arr[10] = {10,8,6,4,3,7,2,1,9};

  // bubble sort implementation
  // time complexity -> O(n^2) for both worst and best case
  int i,j;
  for(i=0;i<10;i++){
    for(j=0;j<10-i-1;j++){
      if(arr[j] > arr[j+1]){
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }

  for(i=0;i<10;i++){
    std::cout << arr[i] << '\n';
  }

  return 0;
}
