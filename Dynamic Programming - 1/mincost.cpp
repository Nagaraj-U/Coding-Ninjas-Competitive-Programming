
/*
given matrix finf min cost reach from upperleft corner to bottom right
1 2 3
1 5 1
5 4 3
mincost = 7 (1,2,1,3) 
moves can be right,left,diagonal
*/
#include<bits/stdc++.h>

using namespace std;


int mincost(int** input,int si,int sj,int ei,int ej){
    if(si==ei && sj == ej){
        return input[ei][ej];
    }
    if(si > ei || sj > ej ){
        return INT_MAX;
    }
    int path1 = mincost(input,si+1,sj,ei,ej); //moving left
    int path2 = mincost(input,si,sj+1,ei,ej); //moving down
    int path3 = mincost(input,si+1,sj+1,ei,ej); //moving diagonal
    int cost = input[si][sj] + min(path1, min(path2,path3));
    return cost;
}


int mincost1(int** input,int si,int sj,int ei,int ej,int** output){
    if(si==ei && sj == ej){
        return input[ei][ej];
    }
    if(si > ei || sj > ej ){
        return INT_MAX;
    }

    if(output[si][sj] > -1){
        return output[si][sj];
    }

    int path1 = mincost(input,si+1,sj,ei,ej);
    int path2 = mincost(input,si,sj+1,ei,ej);
    int path3 = mincost(input,si+1,sj+1,ei,ej);
    int cost = input[si][sj] + min(path1, min(path2,path3));

    output[si][sj] = cost;
    return cost;
}

int mincost3(int** input,int m,int n){
    int** output = new int*[m];
    for(int i=0;i<m;i++){
        output[i] = new int[n];
    }
   
    output[m-1][n-1] = input[m-1][n-1];
    for(int i=m-2;i>=0;i--){
        output[i][n-1] = output[i+1][n-1] + input[i][n-1];
    }

    for(int j=n-2;j>=0;j--){
        output[m-1][j] = output[m-1][j+1] + input[m-1][j];
    }

    for(int i=m-2;i>=0;i--){
        for(int j=n-2;j>=0;j--){
            output[i][j] = input[i][j] + min(output[i+1][j],min(output[i+1][j+1],output[i][j+1]));
        }
    }
    return output[0][0];
}

int main(){
   int m,n;
    cin >> m;
    cin >> n;
    int** arr = new int*[m];
    for(int i=0;i<m;i++){
        arr[i] = new int[n];
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }

    int** output = new int*[m];
    for(int i=0;i<m;i++){
        output[i] = new int[n];
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            output[i][j] = -1;
        }
    }

    int cost = mincost(arr,0,0,m-1,n-1);
    int cost1 = mincost1(arr,0,0,m-1,n-1,output);
    int cost3 = mincost3(arr,m,n);

    cout <<"minimum cost (exponential time) " << cost << endl;
    cout << "minimum cost (reduced time by storing values ) " << cost1 << endl;
    cout << "minimum cost (iterative) " << cost3 << endl;
    return 0;
    
}


