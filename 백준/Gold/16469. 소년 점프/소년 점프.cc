#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 101
#define INF 987654321

struct Point {
    int x, y;
};

int r, c;
int maze[MAX][MAX];
int dist[3][MAX][MAX];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
Point start[3];

void bfs(int idx, int x, int y) {
    queue<Point> q;
    dist[idx][x][y] = 0;
    q.push({x, y});

    while (!q.empty()) {
        Point cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
            if (maze[nx][ny] == 1) continue;
            if (dist[idx][nx][ny] != -1) continue;

            dist[idx][nx][ny] = dist[idx][cur.x][cur.y] + 1;
            q.push({nx, ny});
        }
    }
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            char ch;
            cin >> ch;
            maze[i][j] = ch - '0'; 
        }
    }

    for (int i = 0; i < 3; i++) {
        cin >> start[i].x >> start[i].y;
        start[i].x--; // 시작을 0으로
        start[i].y--;
    }

    // 초기화
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < r; j++)
            for (int k = 0; k < c; k++)
                dist[i][j][k] = -1;

    // BFS 실행
    for (int i = 0; i < 3; i++)
        bfs(i, start[i].x, start[i].y);

    int minTime = INF;
    int count = 0;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (dist[0][i][j] == -1 || dist[1][i][j] == -1 || dist[2][i][j] == -1) continue;

            int t = max({dist[0][i][j], dist[1][i][j], dist[2][i][j]});
            if (t < minTime) {
                minTime = t;
                count = 1;
            } else if (t == minTime) {
                count++;
            }
        }
    }

    if (minTime == INF) cout << -1 << "\n";
    else cout << minTime << "\n" << count << "\n";

    return 0;
}
