#include <iostream>
#include<vector>
#include<queue>
using namespace std;

#define MAX 101

int N ,M; //(N,N)에서 (1,1)부터 시작 // 불이 켜져있는 방으로만 갈 수 있다 // 상하좌우 인접한 방으로만 갈 수 있다.
vector<pair<int, int> > switches[MAX][MAX];
int visited[MAX][MAX];
int light[MAX][MAX];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};



bool isRange(int x, int y) {
    return x >= 1 && x <= N && y >= 1 && y <= N;
}

int bfs() {
    queue<pair <int, int> >q;
    q.push(make_pair(1,1));
    visited[1][1] = 1;
    light[1][1] = 1;

    int result = 1;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        // 현재 방에서 다른 불 켜기 가능한 방 불 켜기
        for (int i = 0; i < switches[x][y].size(); i++) {
            int a = switches[x][y][i].first;
            int b = switches[x][y][i].second;

            if (!light[a][b]) {
                light[a][b] = 1;
                result++;

                for (int j = 0; j < 4; j++) {
                    int na = a + dx[j];
                    int nb = b + dy[j];

                    if (isRange(na, nb) && visited[na][nb]) {
                        visited[a][b] = 1;
                        q.push(make_pair(a,b));
                        break;
                    }
                }
            }
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if ( !isRange(nx, ny) || visited[nx][ny] ||!light[nx][ny] ) continue;

            visited[nx][ny] = 1;
            q.push(make_pair(nx,ny));
        }
    }
    return result;
}

int main() {cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    cin >> N >> M;

    while (M--) {
        int x, y, a, b;
        cin >> x >> y >> a >> b; //(x,y) 방에서 (a,b)방의 불을 켤 수 있다.
        switches[x][y].push_back(make_pair(a,b));
    }

    cout << bfs() << '\n';
}