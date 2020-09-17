/*
Coding Ninjas
Send Feedback
Given a NxM matrix containing Uppercase English Alphabets only. Your task is to tell if there is a path in the given matrix which makes the sentence “CODINGNINJA” .
There is a path from any cell to all its neighbouring cells. A neighbour may share an edge or a corner.
Input Format :
Line 1 : Two space separated integers N  and M, where N is number of rows and M is number of columns in the matrix.
Next N lines : N rows of the matrix. First line of these N line will contain 0th row of matrix, second line will contain 1st row and so on
Assume input to be 0-indexed based
Output Format :
Return 1 if there is a path which makes the sentence “CODINGNINJA” else return 0.
Constraints :
1 <= N <= 100
1 <= M <= 100
Sample Input :
2 11
CXDXNXNXNXA
XOXIXGXIXJX
Sample Output :
1
*/

bool check(char Graph[][MAXN],string str,int n,int m,int i,int j,bool** visited){
    
    if(str.length() == 0){  //string is found ("ODINGNINJA") except 'C'
        return true;
    }
    
    if(i >= n || i < 0 || j >= m || j < 0){
        return false;
    }
    
    
    if((i-1 >= 0 && j-1 >= 0) && !visited[i-1][j-1] && Graph[i-1][j-1] == str[0]){
        visited[i-1][j-1] = true;
        bool ans = check(Graph,str.substr(1),n,m,i-1,j-1,visited);
        if(ans){
            return true;
        }else{
            visited[i-1][j-1] = false;
        }
    } 
    
    if((i-1 >= 0 && j >= 0) && !visited[i-1][j] && Graph[i-1][j] == str[0]){
        visited[i-1][j] = true;
        bool ans = check(Graph,str.substr(1),n,m,i-1,j,visited);
        if(ans){
            return true;
        }else{
            visited[i-1][j] = false;
        }
    }
    
    if((i-1 >= 0 && j+1 < m) && !visited[i-1][j+1] && Graph[i-1][j+1] == str[0]){
        visited[i-1][j+1] = true;
        bool ans = check(Graph,str.substr(1),n,m,i-1,j+1,visited);
        if(ans){
            return true;
        }else{
            visited[i-1][j+1] = false;
        }
    }
    
    if((i >= 0 && j+1 < m) && !visited[i][j+1] && Graph[i][j+1] == str[0]){
        visited[i][j+1] = true;
        bool ans = check(Graph,str.substr(1),n,m,i,j+1,visited);
        if(ans){
            return true;
        }else{
            visited[i][j+1] = false;
        }
    }
    
    if((i >= 0 && j-1 >= 0) && !visited[i][j-1] && Graph[i][j-1] == str[0]){
        visited[i][j-1] = true;
        bool ans = check(Graph,str.substr(1),n,m,i,j-1,visited);
        if(ans){
            return true;
        }else{
            visited[i][j-1] = false;
        }
    }
    
    if((i+1 < n && j-1 >= 0) && !visited[i+1][j-1] && Graph[i+1][j-1] == str[0]){
        visited[i+1][j-1] = true;
        bool ans = check(Graph,str.substr(1),n,m,i+1,j-1,visited);
        if(ans){
            return true;
        }else{
            visited[i+1][j-1] = false;
        }
    }
    
    if((i+1 < n && j >=0) && !visited[i+1][j] && Graph[i+1][j] == str[0]){
        visited[i+1][j] = true;
        bool ans = check(Graph,str.substr(1),n,m,i+1,j,visited);
        if(ans){
            return true;
        }else{
            visited[i+1][j] = false;
        }
    }
    
    if((i+1 < n && j+1 < m) && !visited[i+1][j+1] && Graph[i+1][j+1] == str[0]){
        visited[i+1][j+1] = true;
        bool ans = check(Graph,str.substr(1),n,m,i+1,j+1,visited);
        if(ans){
            return true;
        }else{
            visited[i+1][j+1] = false;
        }
    }
    
    
    
    
    
    
    
    
    
    
    
    
//     int rows[] = {i-1,i,i+1};
// 	int cols[] = {j-1,j,j+1};
    
//     for(int k=0;k<3;k++){
//         for(int l=0;l<3;l++){
            
//             int row = rows[k];
//             int col = cols[l];
            
            
//             //works fine without below code also
//             if(rows[row] == i && cols[col] == j){
//                 continue;
//             }
            
//             if(row < 0 || col < 0 || row >= n || col >= m){  //row array may cross index bounds
//                 continue;
//             }
              
//             if(!visited[row][col] && Graph[row][col] == str[0]){
//                 visited[row][col] = true;
//                 bool ans = check(Graph,str.substr(1),n,m,row,col,visited);
//                 if(ans){
//                     return true;
//                 }else{
//                     visited[row][col] = false;
//                 }
//             }
//         }
    // }
    
    return false;
    
}


int solve(char Graph[][MAXN],int n, int m)
{
    
    string str = "CODINGNINJA";
    
    bool** visited = new bool*[n];
    for(int i=0;i<n;i++){
        visited[i] = new bool[m];
        for(int j=0;j<m;j++){
            visited[i][j] = false;
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(Graph[i][j] == 'C'){
                if(check(Graph,str.substr(1),n,m,i,j,visited)){
                    return 1;
                }
                
                // for(int k=0;k<n;k++){
                //     for(int l=0;l<m;l++){
                //         visited[k][l] = false;
                //     }
                // }
                visited[i][j] = false;
            }
        }
    }
    return 0;
   	
}
