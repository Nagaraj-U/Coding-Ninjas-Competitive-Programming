/*
Time complexity : best and avg O(n*log n)

worst case : when elements are  in sorted order 
after first pass (left = 0 , right = n-1) , after second (left = 0,right = n-2) , so total (n*n) in worst case 
recurrence relation t(n) = t(n-1) + n
*/

#include<bits/stdc++.h>
int partition(int input[],int start,int end)
{
    int pivot = input[start];
    int i = start;
    int j = end;
    int countSmaller = 0;
    
    //count number of smaller elements that current pivot and place pivot to correct position
    for(int k=start+1;k<=end;k++){
        if(input[k] <= pivot){
            countSmaller++;
        }
    }
    int pivotIndex = start + countSmaller;
    int temp = input[pivotIndex];
    input[pivotIndex] = pivot;
    input[start] = temp;
    
    
    //put all elements <= pivot in left and elements >= pivot in right side 
    //(Note : elements in left and right after placing need not to be in sorted order)
    while(i < pivotIndex && j > pivotIndex){
        if(input[i] <= pivot){
            i++;
        }else if(input[j] > pivot){
            j--;
        }else{ //swap since they are not in correct side
            int temp = input[i];
            input[i] = input[j];
            input[j] = temp;
            i++;
            j--;
        }
    }
    
    return pivotIndex;
}

void helper(int input[],int start,int end)
{
    if(start >= end){
        return;
    }
    int loc = partition(input,start,end);
    helper(input,start,loc-1);
    helper(input,loc+1,end);
    
}

void quickSort(int input[], int size) {
 	helper(input,0,size-1);
    return;
}
