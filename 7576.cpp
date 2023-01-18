#include<iostream>
#include<queue>
#include<vector>
using namespace std;

#define MAX 1001

int graph[MAX][MAX];
int visited[MAX][MAX];
int dist[MAX][MAX];//며칠 걸리는 지 저장
queue< pair<int,int> > q;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int M=0,N=0; //가로 세로

void BFS(){
    while(!q.empty()){
        int tmp_x = q.front().first;
        int tmp_y = q.front().second;
        q.pop();
        
        for(int i =0; i < 4; i++){
            int new_x = tmp_x + dx[i];
            int new_y = tmp_y + dy[i];
            
            if (new_x < 0 || new_y < 0 || new_x >= N || new_y >= M)
                continue;
            if(graph[new_x][new_y] == 0 && visited[new_x][new_y] ==0){
                q.push(make_pair(new_x,new_y));
                visited[new_x][new_y] =1;
                dist[new_x][new_y] = dist[tmp_x][tmp_y]+1;
            }
        }
    }
}

int main(){cin.tie(0); cout.tie(0);
    
    cin >> M>>N;
    
    for(int i=0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> graph[i][j];
        }
    }
    
    for(int i=0; i < N; i++){ //토마토 찾기
        for(int j = 0; j < M; j++){
            if(graph[i][j] == 1){
                q.push(make_pair(i,j));
            }
        }
    }
    BFS();
    
    for(int i=0; i < N; i++){ //안 익은 거 확인
        for(int j = 0; j < M; j++){
            if(graph[i][j] == 0 && dist[i][j] == 0){
                cout << "-1";
                return 0;
            }
        }
    }
    
    int result = 0;
    for(int i=0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(dist[i][j] > result) result = dist[i][j];
        }
    }
    
    cout << result;
    
}