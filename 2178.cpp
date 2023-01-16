#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define MAX 101

int n=0,m=0;
int visited[MAX][MAX];
int graph[MAX][MAX];
int dist[MAX][MAX];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void BFS(int x, int y){
    queue< pair<int, int > > q;
    visited[x][y] = 1;
    q.push( make_pair(x,y));

    while(!q.empty()){
        int tmp_x = q.front().first;
        int tmp_y = q.front().second;

        q.pop();

        for(int i=0; i < 4; i++){
            int new_x = tmp_x + dx[i];
            int new_y = tmp_y + dy[i];

            if((new_x >= 0 && new_x < n) && (new_y >= 0 && new_y < m)
            && !visited[new_x][new_y] && graph[new_x][new_y] ==1){
                q.push( make_pair(new_x,new_y));
                visited[new_x][new_y] = 1;
                dist[new_x][new_y] = dist[tmp_x][tmp_y] +1;
            }
        }
    }
}

int main(){cin.tie(0); cout.tie(0);
    cin >> n>>m;
    string input;

    for(int i=0; i < n; i++){
        cin >> input;

        for(int j =0; j < input.size(); j++){
            graph[i][j] = input[j] - '0';
        }
    }

    BFS(0,0);

    cout << dist[n-1][m-1]+1;
    
}