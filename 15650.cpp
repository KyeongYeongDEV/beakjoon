#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int graph[11][11];
int visited[11];

void dfs(int cur, int n){
    visited[cur] =1;
    for(int i=1; i <=n; i++){
        if(graph[cur][i] ==1 && visited[i] ==0){//인접하고 방문하지 않았다면
            cout << i;
            dfs(i,n);
        }
    }
}

int main(){cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int start =1; 

    graph[1][3]=1;graph[3][5]=1; graph[5][7] =1;
    graph[3][1]=1;graph[5][3]=1; graph[7][5] =1;

    graph[1][2]=1;graph[2][4]=1; graph[4][8] =1;
    graph[2][1]=1;graph[4][2]=1; graph[8][4] =1;

    cout << start;
    dfs(start,10);

    return 0;
}