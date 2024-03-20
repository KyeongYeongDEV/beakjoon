#include<iostream>
#include<vector>

using namespace std;

int n, result = 0;
char graph[101][101];
int visited[101][101] = {0,};

typedef struct Point{
    int x, y;
}Point;

Point p[4] = {{0,1},{1,0}, {0,-1},{-1,0}};

void initialize(){
    for(int i=0; i < n; i++){
        for(int j=0; j < n; j++){
            visited[i][j] = 0;
        }
    }
    result = 0;
}


void dfs(int nx, int ny){
    if(visited[nx][ny]) return;

    visited[nx][ny] = 1;

    for(int i=0; i < 4; i++){
        int dx = p[i].x + nx;
        int dy = p[i].y + ny;

        // 다음 좌표가 색이 같고 방문하지 않았다면
        if(graph[nx][ny] == graph[dx][dy] && !visited[dx][dy]){
            dfs(dx,dy);
        }
    }
}

void findSection(){
    for(int i=0; i < n; i++){
        for(int j=0; j < n; j++){
            // 방문을 하지 않은 구역 다 돌기
            if(!visited[i][j]){
                dfs(i,j);
                result++;
            }
        }
    }

    cout << result << " ";
}

void changeGtoR(){
    for(int i=0; i < n; i++){
        for(int j=0; j < n; j++){
            if(graph[i][j] == 'G'){
                graph[i][j] = 'R';
            }
        }
    }
}


int main(){cout.tie(0); cin.tie(0); ios::sync_with_stdio(0);
    cin >> n;

    for(int i=0; i < n; i++){
        cin >> graph[i];
    }


    findSection();
    initialize();
    changeGtoR();
    findSection();
}