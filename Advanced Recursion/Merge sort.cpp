/*
Sort an array A using Merge Sort.
Change in the input array itself. So no need to return or print anything.

Input format :
Line 1 : Integer n i.e. Array size
Line 2 : Array elements (separated by space)

Output format :
Array elements in increasing order (separated by space)

Constraints :
1 <= n <= 10^3

Sample Input 1 :
6 
2 6 8 5 4 3

Sample Output 1 :
2 3 4 5 6 8

Sample Input 2 :
5
2 1 5 2 3

Sample Output 2 :
1 2 2 3 5 

*/


#include <iostream>
using namespace std;

void merge(int* arr1,int n1,int* arr2,int n2,int* input,int size){
    int i = 0;
    int j = 0;
    int k = 0;
    while(i<n1 && j<n2){
        if(arr1[i] < arr2[j]){
            input[k++] = arr1[i++];
        }else{
            input[k++] = arr2[j++];
        }
    }
    while(i < n1){
            input[k++] = arr1[i++];
        }
    while(j < n2){
            input[k++] = arr2[j++];
        }
}

void mergeSort(int input[], int size){
    
    if(size == 1 || size == 0){
        return;
    }
    
    int n1 = size/2;
    int n2 = size - n1;
    int* arr1 = new int[n1];
    int* arr2 = new int[n2];
    for(int i=0;i<n1;i++){
        arr1[i] = input[i];
    }
    int k=0;
    for(int j=n1;j<size;j++){
        arr2[k++] = input[j];
    }
    
    mergeSort(arr1,n1);
    mergeSort(arr2,n2);
    merge(arr1,n1,arr2,n2,input,size);
 }


int main() {
  int length;
  cin >> length;
  int* input = new int[length];
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}
