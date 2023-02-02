#include<iostream>
#include<queue>
using namespace std;

#define MAX 100001

int n=0,k=0;
int dp[MAX];
int point[3] = {2,1,-1};

void bfs(){
    queue<int> q;
    q.push(n);
    dp[n] = 0;

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        if(cur == k){
            cout << dp[cur];
            break;
        }
        int next=0, time=0;
        for(int i=0; i <3; i++){
            if(i == 0){
                next = cur * point[i];
                time = 0;
            }else{
                next = cur + point[i];
                time = 1;
            }

            if(next >= 0 && next < MAX && dp[next] > dp[cur] + time){
                dp[next] = dp[cur] + time;
                q.push(next);
            }
        }
    }
}

int main(){cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n >> k;
    fill_n(dp,MAX,987654321);
    bfs();
}