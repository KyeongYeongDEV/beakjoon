#include<iostream>
#include<queue>
#include<string.h>

using namespace std;

typedef struct Point{
    int x,y;
}Point;

int n, m, result = 0, hour = -1;
int graph[101][101] = {0,};
int visited[101][101] = {0,};
Point p[4] = {{0,1},{1,0},{-1,0},{0,-1}};

int bfs(){
    visited[0][0] = 1;
    int cnt =0;
    hour++;
    
    queue< pair<int,int>> q;
    q.push({0,0});

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i =0; i < 4; i++){
            int nx = x + p[i].x;
            int ny = y + p[i].y;

            if(nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny]){
                if(graph[nx][ny] == 0){
                    q.push({nx,ny}); 
                }else{
                    graph[nx][ny] = 0;
                    cnt++;
                }
                visited[nx][ny] = 1;
            }
        }
    }

    if(cnt == 0){
        cout << hour << "\n" << result;
        return 1;
    }else{
        result = cnt;
        return 0;
    }
}

int main(){cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n >> m;

    for(int i=0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> graph[i][j];
        }
    }

    while(1){
        if(bfs()){
            break;
        }
        memset(visited, 0, sizeof(visited));
    }

}