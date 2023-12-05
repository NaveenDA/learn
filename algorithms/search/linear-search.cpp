#include <iostream>

int main(){

  int arr[5] = {20,30,60,50,90};

// linear search implementation

  int key = 50;
  int i;
  for(i=0;i<5;i++){
    if(arr[i] == key){
      std::cout << "Element found at index " << i << '\n';
      break;
    }
  }
  
  return  0;
}
