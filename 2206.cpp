#include<iostream>
#include<queue>
using namespace std;

#define MAX 1001

string graph[MAX];
int dist[MAX][MAX][2] = {0,};
int r=0,c=0;

struct point{
    int x;
    int y;    
}point[4] = {{0,1},{0,-1}, {1,0}, {-1,0}};

int bfs(){
    queue<pair<pair<int, int>, int> > q;
    q.push(make_pair(make_pair(0,0),1));
    dist[0][0][1] = 1;

    while(!q.empty()){
        int cur_r = q.front().first.first;
        int cur_c = q.front().first.second;
        int block = q.front().second;
        q.pop();

        if(cur_r == r-1 && cur_c == c-1){ //도착
            return dist[cur_r][cur_c][block];
        }

        for(int i=0; i < 4; i++){
            int next_r = cur_r + point[i].x;
            int next_c = cur_c + point[i].y;
            
            if(next_r >= 0 && next_r < r && next_c >= 0 && next_c < c){//미로 범위 내에서
                if(graph[next_r][next_c] == '1' && block == 1){ //다음이 벽이고 부술 수 있을 때
                    dist[next_r][next_c][block-1] = dist[cur_r][cur_c][block] + 1;
                    q.push(make_pair(make_pair(next_r,next_c),0));
                }
                else if(graph[next_r][next_c] == '0' && dist[next_r][next_c][block] == 0){//벽이 아니고 방문을 안 했을 때
                    dist[next_r][next_c][block] = dist[cur_r][cur_c][block] + 1;
                    q.push(make_pair(make_pair(next_r,next_c),block));
                }
            }
        }
    }

    return -1;
}

int main(){ cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> r >> c;

    for(int i=0; i < r; i++){
        cin >> graph[i];
    }

    cout << bfs();
}