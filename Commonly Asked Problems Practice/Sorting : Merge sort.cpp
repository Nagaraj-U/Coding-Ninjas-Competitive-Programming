
void merge(int arr[],int start,int mid,int end)
{
    int* temp = new int[end-start+1]; //to sort in range (start,end)
    int i=start,j=mid+1,k=0;
    while(i<=mid && j<=end){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }else{
            temp[k++] = arr[j++];
        }
    }
    
    while(i <= mid){
        temp[k++] = arr[i++];
    }
    while(j <= end){
        temp[k++] = arr[j++];
    }
    
    for(int p=0;p<k;p++){ //copy to original position in old array
        arr[p + start] = temp[p];
    }
    
    return;
}

void helper(int arr[],int start,int end)
{
    if(start < end){
        int mid = (start+end)/2;
        helper(arr,start,mid);
        helper(arr,mid+1,end);
        merge(arr,start,mid,end);
    }
    
    return;
}

void mergeSort(int input[], int size){
	// Write your code here

   	helper(input,0,size-1);
    return;
        
}
