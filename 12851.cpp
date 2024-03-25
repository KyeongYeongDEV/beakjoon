#include<iostream>
#include<queue>
using namespace std;

#define MAX 100001

int d[3] = {1, -1, 2};
int dist[MAX] = {0,};
int cnt[MAX] = {0,};
int n,k, result = 0;

void bfs(){
    queue<int> q;
    q.push(n);

    cnt[n] = 1;

    while(!q.empty()){
        int x = q.front();  q.pop();

        for(int nx : {x + 1, x -1, x * 2}){
            if(nx < 0 || nx > MAX) continue;

            if(dist[nx]) { // 이미 방문을 했다면
                if(dist[x]+1 == dist[nx]){
                    cnt[nx] += cnt[x];
                }
            }else{ // 첫 방문이면
                dist[nx] = dist[x] +1;
                cnt[nx] = cnt[x];
                q.push(nx);
            }
        }
    }
}

int main(){cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n >> k;

    if(n == k){
        cout << 0 << "\n" << 1;
        return 0;
    }   
    bfs();

    cout << dist[k] << "\n" << cnt[k];
}