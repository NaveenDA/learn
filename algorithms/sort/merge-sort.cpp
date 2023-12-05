#include <iostream>
using namespace std;

void mergeSort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);

int main() {
    int arr[10] = {10, 8, 6, 4, 3, 7, 2, 1, 9};

    // merge sort implementation
    cout << "Before sorting" << '\n';
    for (int i = 0; i < 10; i++) {
        cout << arr[i] ;
    }
    mergeSort(arr, 0, 9);
    cout << "After sorting" << '\n';
    for (int i = 0; i < 10; i++) {
        cout << arr[i] ;
    }

    return 0;
}


void mergeSort(int arr[], int l, int r){
  if(l<r){
    int m = (l+r)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
  }
}

void merge(int arr[], int l, int m, int r){
  int i,j,k;
  int n1 = m-l+1;
  int n2 = r-m;

  int L[n1], R[n2];

  for(i=0;i<n1;i++){
    L[i] = arr[l+i];
  }
  for(j=0;j<n2;j++){
    R[j] = arr[m+1+j];
  }

  i=0;
  j=0;
  k=l;

  while(i<n1 && j<n2){
    if(L[i] <= R[j]){
      arr[k] = L[i];
      i++;
    }
    else{
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while(i<n1){
    arr[k] = L[i];
    i++;
    k++;
  }

  while(j<n2){
    arr[k] = R[j];
    j++;
    k++;
  }
}