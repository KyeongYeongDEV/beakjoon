#include<iostream>
#include<queue>
using namespace std;
#define MAX 101

int graph[MAX][MAX][MAX]={0,};
int dist[MAX][MAX][MAX]={0,};

int dx[6] = {0,0,0,0,1,-1};
int dy[6] = {0,0,1,-1,0,0};
int dz[6] = {1,-1,0,0,0,0};

int x=0,y=0,z=0;
queue<pair<int, pair<int,int> > > q;

void bfs(){
    while(!q.empty()){
        int tz = q.front().first;
        int tx = q.front().second.first;
        int ty = q.front().second.second;
        
        q.pop();
        
        for(int i = 0;  i<6; i++){
            int nz = tz + dz[i];
            int nx = tx + dx[i];
            int ny = ty + dy[i];
            
            if(!((0 <= nx && nx < y) && (0 <= ny && ny < x) && (0 <= nz && nz < z))) continue;
            if(dist[nz][nx][ny]  != 0 || graph[nz][nx][ny] != 0)continue;     

            q.push(make_pair(nz, make_pair(nx,ny)));
            dist[nz][nx][ny] = dist[tz][tx][ty] + 1;
        }
    }
}


int main(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> x>> y >> z;
    
    for(int k =0; k < z; k++){
        for(int i=0; i < y; i++){
            for(int j =0; j < x; j++){
                cin >> graph[k][i][j];
                
                if(graph[k][i][j] == 1){ //토마토가 들어오면 push
                    q.push(make_pair(k, make_pair(i,j)));
                    dist[k][i][j] = 1;
                }
            }
        }
    }
    
    bfs();
    
    int result = -1;
    for(int k =0; k < z; k++){
        for(int i=0; i < y; i++){
            for(int j =0; j < x; j++){
                if(graph[k][i][j] == 0 && dist[k][i][j] == 0){
                    //안 익은 게 있다면
                    cout << -1;
                    return 0;
                }
                
                if(result < dist[k][i][j]) result = dist[k][i][j];
            }
        }
    }
    cout << result-1;
}