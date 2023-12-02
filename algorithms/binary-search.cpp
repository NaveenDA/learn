#include <iostream>

int main(){

  int arr[15] = {20,30,60,50,90,100,110,120,130,140,150,160,170,180,190,200};

// binary search implementation (iterative)

  int key = 50;
  int low = 0;
  int high = 15;
  int mid;
  while(low <= high){
    mid = (low + high)/2;
    if(arr[mid] == key){
      std::cout << "Element found at index " << mid << '\n';
      break;
    }
    else if(arr[mid] > key){
      high = mid - 1;
    }
    else{
      low = mid + 1;
    }
  }
  
  return  0;
}
