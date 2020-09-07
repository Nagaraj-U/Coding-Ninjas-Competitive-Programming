/*
The difficult economic situation in the country and reductions in government agricultural subsidy funding have caused Mirko to 
change his career again, this time to a thief. His first professional endeavour is a jewellery store heist.

The store contains N pieces of jewellery, and each piece has some mass Mi and value Vi. Mirko has K bags to store his loot, and each bag can hold 
some maximum mass Ci. He plans to store all his loot in these bags, but at most one jewellery piece in each bag, in order to reduce the likelihood 
of damage during the escape.

Find the maximum total jewellery value that Mirko can "liberate".

Input
The first line of input contains two numbers, N and K (1≤N,K≤300000).

Each of the following N lines contains a pair of numbers, Mi and Vi (1≤Mi,Vi≤1000000).

Each of the following K lines contains a number, Ci (1≤Ci≤100000000).

All numbers in the input are positive integers.

Output
The first and only line of output must contain the maximum possible total jewellery value.

Scoring
In test data worth at least 50% of total points, N and K will be less than 5000.

Sample Input 1
Copy
2 1
5 10
100 100
11
Sample Output 1
Copy
10
Sample Input 2
Copy
3 2
1 65
5 23
2 99
10
2
Sample Output 2
Copy
164

*/

#include<bits/stdc++.h>
using namespace std;

struct Jewel{
    int mass;
    int value;
};

bool compare(Jewel j1,Jewel j2){
    if(j1.value == j2.value){
        return j1.mass < j2.mass;
    }
    return j1.value > j2.value;
}

int main(){
    int n,k;
    cin >> n >> k;
    Jewel* arr = new Jewel[n];
    for(int i=0;i<n;i++){
        cin >> arr[i].mass;
        cin >> arr[i].value;
    }
    sort(arr,arr+n,compare);
    multiset<int> m;  //item repetition is allowed
    for(int i=0;i<k;i++){
        int c;
        cin >> c;
        m.insert(c);
    }
    long ans = 0;
    for(int i=0;i<n;i++){
        if(m.empty()){
            break;
        }else if(m.lower_bound(arr[i].mass) != m.end()){  //find bag having mass just >= mass of jewel 
            ans += arr[i].value;
            m.erase(m.lower_bound(arr[i].mass)); //delete bag
        }
    }
    cout << ans << endl;
    return 0;
}
