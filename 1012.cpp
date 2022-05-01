#include<iostream>
#include<queue>
using namespace std;

int M,N,K;
int arr[51][51] = {0,};
bool check[51][51]={false,};
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
queue<pair<int, int>> q;

void bfs(int x,int y){
    q.push(make_pair(x,y));

    while(!q.empty()){
        int a = q.front().first; // x
        int b = q.front().second;// y

        q.pop();
        check[a][b]=true;

        for(int i =0; i < 4; i++){
            int nx = a + dx[i];
            int ny = b + dy[i];

            if(0 <= nx && 0 <= ny && nx <N && ny < M &&
                !check[nx][ny] && arr[nx][ny] ==1){
                q.push({ nx,ny });
                check[nx][ny] = true;
            }
        }
    }
}

void reset(){
    while(!q.empty()){ //큐가 빌 때까지 
        q.pop();
    }
    for(int i =0; i < N;i ++){
        for(int j =0 ; i <M; j++){
            check[i][j] = false;
            arr[i][j] = 0;
        }
    }
}

int main(){cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int T;
    cin>> T;

    for(int t = 0; t< T; t++){
        int cnt =0;
        reset();

        cin >> M>>N>>K; //가로, 세로, 배추의 수

        for(int i =0; i< K; i++){
            int x,y;
            cin >>x>>y;
            arr[x][y] = 1; //배추가 심어져 있는 곳에 1
        }

        for(int i = 0; i <N; i++){
            for(int j = 0; j < M; j++){
                if(arr[i][j] ==1 && !check[i][j]){
                    bfs(i,j);
                    cnt++;
                }
            }
        }

        cout << cnt<<"\n";
    }
}