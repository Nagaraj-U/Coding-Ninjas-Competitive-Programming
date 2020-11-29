/*
Calculate Grundy Number
Send Feedback
Calculate the Grundy Number for the given 'n' in the game.
The game starts with a number- ‘n’ and the player to move divides the number- ‘n’ with 2, 3 or 6 and then takes the floor. If the integer becomes 0, it is removed. The last player to move wins. Which player wins the game?
Input Format
An Integer 'n'
Output Format
Grundy Number(n)
Sample Input 1 -
10
Sample Output 1-
0
*/


#include<bits/stdc++.h>
using namespace std;

/*
MEX : minimum excludant set
set s = {1,2,3} -> mex(s) = 0
set s1 = {0,2,3} -> mex(s1) = 1
set s2 = {0,1,2,3} -> mex(s2) = 4
set s3 = {0,1,2,3,5} -> mex(s3) = 4
*/

int mex(int n1,int n2,int n3){
    set<int> temp;
    temp.insert(n1);
    temp.insert(n2);
    temp.insert(n3);
    
    int maximum = max(n1,max(n2,n3));
    for(int i=0;i<=maximum;i++){
        if(temp.count(i) == 0){  //checking for minimum element which is not present
            return i; //return minimum non-negative element in set
        }
    }
    
    return maximum+1;  //else return next maximum element which is mex in given set
}

int grundy(int n){
    if(n == 0){
        return 0; //grundy(0) = 0 from zero'th state we cant move further
    }
    
    return mex(grundy(n/2),grundy(n/3),grundy(n/6));
}

int main() {
	int n;
    cin >> n;
    cout << grundy(n) << endl;
}
