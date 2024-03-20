#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<pair<int, int>> node[10001];
int visited[10001];

int n, maxValue = -1, maxNode = 0;

void dfs(int cur, int value){
    visited[cur] = 1;

    if(maxValue < value){
        maxValue = value;
        maxNode = cur;
    }
    for(int i =0; i < node[cur].size(); i++){
        if(!visited[node[cur][i].first]){ // 이미 방문 했으면 패스
            dfs(node[cur][i].first, value + node[cur][i].second);// 현재 누적 가중치  + 이동할 노드의 가중치
        }
    }
}

void initialize(){
    for(int i =0; i <10001; i++){
        visited[i] = 0;
    }
    maxValue = -1;
}

int main(){cout.tie(0); cin.tie(0); ios::sync_with_stdio(0);
    cin >> n;

    for(int i=0; i< n-1; i++){
        int a, b, c;
        cin >> a >> b >>c;

        node[a].push_back({b,c});
        node[b].push_back({a,c});
    }

    dfs(1, 0); // 루트에서 가장 먼 곳 찾기 
    initialize();
    dfs(maxNode, 0);

    cout << maxValue;
}