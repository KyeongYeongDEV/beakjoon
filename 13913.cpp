#include<iostream>
#include<queue>
#include<stack>
using namespace std;

#define MAX 100001

int n, k, result,tmp = 0;
int dx[3] = {-1, 1, 2};

int dis[MAX] = {0,}; 
int path[MAX] = {0,};

void bsf(){
    queue<int> q;
    q.push(n);

    path[n] =n;
    dis[n] = 1;

    while(!q.empty()){
        int x = q.front();
        q.pop();

        for(int i=0; i < 3; i++){
            int nx = x;
            if(i == 2){
                nx *= dx[i];
            }else{
                nx += dx[i];
            }

            if(nx < 0 || nx > MAX) continue;
            if(dis[nx]) continue;

            dis[nx] = dis[x] + 1;
            path[nx] = x; 
            q.push(nx);
        }
    }
}

int main(){cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n >> k; // 언니, 동생

    bsf();
    int result = dis[k] -1;
    cout << result<< "\n";

    int cur = k;

    int tmp = 0;
    int arr[MAX] = {0,};
    arr[tmp++] = k;
    
    while(result--){
        arr[tmp++] = path[cur];
        cur = path[cur];
    }

    for(int i=tmp-1; i >=0 ; i--){
        cout << arr[i] << " ";
    }
    
}