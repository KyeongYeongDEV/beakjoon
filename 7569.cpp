#include<iostream>
#include<queue>
using namespace std;
#define MAX 100000

queue<pair<int, int> > q; //위치, 초
int visited[200001];
int n=0, m=0; // 언니 동생

void bfs(){
    q.push(make_pair(n, 0));
    visited[n] = 1;

    while(!q.empty()){
        int x = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if(x < 0|| x > MAX) continue;

        if(x == m){
            cout << cnt;
            break;
        }
        if(!visited[x+1]){
            q.push(make_pair(x+1, cnt+1));
            visited[x+1] = 1;
        }
        if(!visited[x - 1]){
            q.push(make_pair(x - 1, cnt+1));
            visited[x-1] = 1;
        }
        if(!visited[x*2]){
            q.push(make_pair(x*2, cnt+1));
            visited[x*2] = 1;
        }
    }
}

int main(){cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n >> m;
    bfs();
}