
/*
We are given an array consisting of n elements. At each operation you can select any one element
 and increase rest of n-1 elements by 1. You have to make all elements equal performing 
 such operation as many times you wish. Find the minimum number of operations needed for this.


 Input : arr[] = {1, 2, 3}
Output : Minimum Operation = 3
Explanation : 
operation | increased elements | after increment
    1     |    1, 2            | 2, 3, 3
    2     |    1, 2            | 3, 4, 3
    3     |    1, 3            | 4, 4, 4


Input : arr[] = {4, 3, 4}
Output : Minimum Operation = 2
Explanation : 
operation | increased elements | after increment
     1    |    1, 2           | 5, 4, 4
     2    |    2, 3           | 5, 5, 5



Brute force : A simple way to make all elements equal is that at each step find the largest elements 
and then increase all rest n-1 elements by 1. We should keep doing this operation till all
 elements become equal. Time Complexity : O(n^2)
*/

#include<bits/stdc++.h>
using namespace std;

/*
approach :
O(N^2)

loop
select largest element from array
increment all other element except larger element
do this until all elements equal
end loop

O(N)

if we think in reverse direction 
above approach is equivalent to
selecting smaller element from array , reducing all other element to this value

*/
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int mini = INT_MAX;
    for(int i=0;i<n;i++){
        mini = min(mini,arr[i]);
    }
    int count = 0;
    for(int i=0;i<n;i++){
        count += (arr[i] - mini);
    }
    cout << count << endl;
    return 0;
}
