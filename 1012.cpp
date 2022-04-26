#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

void BFS(int start,vector<int> graph[], bool check[]){
    queue<int> q;

    q.push(start);
    check[start] = true;

    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        cout << tmp<<" ";
        for(int i =0; i <graph[tmp].size();i++){
            if(check[graph[tmp][i]] == false){
                q.push(graph[tmp][i]);
                check[graph[tmp][i]] = true;
            }
        }
    }
}

int main(){
    int n,m,start;
    cin >> n>>m>>start;//노드수, 엣지수, 시작하는 노드

    vector<int> graph[n+1];

    bool check[n+1];
    fill(check,check+n+1,false);

    for(int i =0; i<m;i++){
        int x,y;
        cin >> x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for(int i =0 ; i < n; i++){ //정렬을 해줘야 순차적으로 접근한다.
        sort(graph[i].begin(),graph[i].end());
    }

    BFS(start,graph,check);

}