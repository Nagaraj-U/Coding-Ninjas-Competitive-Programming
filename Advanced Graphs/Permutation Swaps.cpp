/*
Permutation Swaps
Send Feedback
Kevin has a permutation P of N integers 1, 2, ..., N, but he doesn't like it. Kevin wants to get a permutation Q.

Also he believes that there are M good pairs of integers (ai , bi). Kevin can perform following operation with his permutation:

Swap Px and Py only if (x, y) is a good pair.
Help him and tell if Kevin can obtain permutation Q using such operations.
Input format:
The first line of input will contain an integer T, denoting the number of test cases.

Each test case starts with two space-separated integers N and M. The next line contains N space-separated integers Pi. The next line contains N space-separated integers Qi. Each of the next M lines contains two space-separated integers ai and bi.
Output format:
For every test case output "YES" (without quotes) if Kevin can obtain permutation Q and "NO" otherwise.
Constraints:
1 ≤ T ≤ 10
2 ≤ N ≤ 100000
1 ≤ M ≤ 100000
1 ≤ Pi, Qi ≤ N. Pi and Qi are all distinct.
1 ≤ ai < bi ≤ N
SAMPLE INPUT
2
4 1
1 3 2 4
1 4 2 3
3 4
4 1
1 3 2 4
1 4 2 3
2 4
SAMPLE OUTPUT
NO 
YES
*/



#include<bits/stdc++.h>
using namespace std;

/*
Intuition :
get connected components among M pairs (M edges)

we can change P -> Q  if values present at indexes in P and Q can be swapped if they are inside same connected component
(connected component gives indexes) 

make two sets SP and SQ (insert values of index got from componensts index in SP and SQ)

check if two sets have same values then they can be swapped easily one another else cannot be swapped (hence anwer NO)
make graph for M pairs


*/


//BFS
vector<int> getComponent(int** edges,int m,bool* visited,int n,int start)
{
    vector<int> output;
    queue<int> vertices;
    vertices.push(start);
    visited[start] = true;
    while(!vertices.empty())
    {
        int current = vertices.front();
        vertices.pop();
        output.push_back(current);
        for(int i=0;i<n;i++){
            if(!visited[i] && i != current && edges[current][i] == 1){
                visited[i] = true;
                vertices.push(i);
            }
        }
    }
    return output;
}


int main()
{
	//code
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        int* p = new int[n];
        int* q = new int[n];
        for(int i=0;i<n;i++){
            cin >> p[i];
        }
        for(int i=0;i<n;i++){
            cin >> q[i];
        }
        int** edges = new int*[n];
        for(int i=0;i<n;i++){
            edges[i] = new int[n];
            for(int j=0;j<n;j++){
                edges[i][j] = 0;
            }
        }
        while(m--){
            int start,end;
            cin >> start >> end;
            edges[start-1][end-1] = 1;
            edges[end-1][start-1] = 1;
        }
        vector<vector<int> > components;
        bool* visited  = new bool[n];
        for(int i=0;i<n;i++){
            visited[i] = false;
        }
        for(int i=0;i<n;i++){
            if(!visited[i]){
                vector<int> temp = getComponent(edges,m,visited,n,i);
                components.push_back(temp);
            }
        }
        bool flag = true;
        for(int i=0;i<components.size();i++){
            unordered_set<int> sp;
            unordered_set<int> sq;
            vector<int> curr = components[i];
            for(int j=0;j<curr.size();j++){
                sp.insert(p[curr[j]]);
                sq.insert(q[curr[j]]);
                // cout << curr[j] << " ";
            }
           
            unordered_set<int>::iterator it = sp.begin();
            while(it != sp.end()){
                int search = *it;
                if(sq.find(search) == sq.end()){
                    // cout << "NO" << endl; 
                    flag = false; //mismatch (ex : 1,3,6 and 1,3,7) we can never convert 136 to 137
                    break;
                }
                it++;
            }
            if(flag == false){
                break;
            }
        }
        if(flag){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
	return 0;
}






















/*
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> *graph, int start, bool *isVisited, unordered_set<int> *part){
    isVisited[start] = true;
    part->insert(start);

    for(int i = 0; i < graph[start].size(); i++){
        int next = graph[start][i];
        if(!isVisited[next]){
            dfs(graph, next, isVisited, part);
        }
    }
}

unordered_set< unordered_set<int> *> *getComponent(vector<int> *graph, int n){
    bool *isVisited = new bool[n];
    for(int i = 0; i < n; i++) isVisited[i] = false;

    unordered_set< unordered_set<int> * > *component = new unordered_set< unordered_set<int> * >();
    for(int i = 0; i < n; i++){
        if(!isVisited[i]){
            unordered_set<int> *part = new unordered_set<int>();
            dfs(graph, i, isVisited, part);
            component->insert(part);
        }
    }

    return component;
}

int main(){
    int flag;
    int t;
    cin >> t;
    while(t--){
        flag = 1;
        int n, m;
        cin >> n >> m;

        int *p = new int[n];
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            p[i] = x-1;
        }

        int *q = new int[n+1];
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            q[i] = x-1;
        }

        vector<int> *graph = new vector<int>[n];
        for(int i = 0; i < m; i++){
            int a, b;
            cin >> a >> b;
            graph[a-1].push_back(b-1);
            graph[b-1].push_back(a-1);
        }

        unordered_set< unordered_set<int> * > *component = getComponent(graph, n);

        // for(unordered_set< unordered_set<int> * >::iterator i = component->begin(); i != component->end(); i++){
        //     for(unordered_set<int>::iterator j = (*i)->begin(); j != (*i)->end(); j++){
        //         cout << (*j)+1 << " ";
        //     }
        //     cout << endl;
        // }

        for(unordered_set< unordered_set<int> * >::iterator i = component->begin(); i != component->end(); i++){
            set<int> setA;
            set<int> setB;
            for(unordered_set<int>::iterator j = (*i)->begin(); j != (*i)->end(); j++){
                setA.insert(p[*j]);
                setB.insert(q[*j]);
            }

            if(setA != setB){
                flag = 0;
                cout << "NO" << endl;
                break;
            }
        }

        if(flag) cout << "YES" << endl;
    }
}
*/
