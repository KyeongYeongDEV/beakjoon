#include<iostream>
#include<queue>
#include<string.h>
using namespace std;

typedef struct Point{
    int x,y;
}Point;
Point p[4] = { {0,1}, {1,0}, {0,-1}, {-1,0} };

int n,m, result =0 ,hour = -1;
int visited[101][101] = {0,};
int graph[101][101] = {0,};


int bfs(){
    queue<pair<int,int>> q;
    q.push({0,0});
    visited[0][0] =1;
    hour++;

    int cnt =0;
    
    while(!q.empty()){
        for(int i=0; i < 4; i++){
            int nx = q.front().first + p[i].x;
            int ny = q.front().second + p[i].y;
            q.pop();

            if(nx >= 0 && nx <= n && ny >= 0 & ny <= m && !visited[nx][ny]){
                if(graph[nx][ny] == 1){
                    graph[nx][ny] = 0;
                }else{
                    q.push({nx,ny});
                    cnt++;
                }
                    visited[nx][ny] = 1;
            }
        }
    }

    if(cnt == 0){ //치즈가 없다
        cout << hour << "\n" << result;
    }else{
        result = cnt;
    }
}

int main(){
    cin >> n >> m;

    for(int i=0; i < n; i++){
        for(int j= 0; j < m; j++){
            cin >> graph[i][j];
        }
    }

    while(1){
        if(bfs()){
            break;
        }
        memset(visited, 0 , sizeof(visited));
    }
}