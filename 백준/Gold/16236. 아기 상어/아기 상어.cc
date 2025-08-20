#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define INF 987654321
#define MAX 20

struct Point {
    int x;
    int y;
};

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int board[MAX][MAX];
int n;
Point shark;           // 상어 현재 위치
int sharkSize = 2;     // 초기 크기
int eaten = 0;         // 현재 크기에서 먹은 물고기 수
int totalTime = 0;     // 정답(총 이동 시간)

// 가장 위 + 왼쪽
bool cmpPoint(const Point& a, const Point& b) {
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}


pair<int, Point> bfs(Point start) {
    int dist[MAX][MAX];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            dist[i][j] = -1;

    queue<Point> q;
    q.push(start);
    dist[start.x][start.y] = 0;

    int bestDist = INF;           // 발견된 먹이의 최소 거리
    vector<Point> candidates;     // 최소 거리인 먹이 후보들

    while (!q.empty()) {
        Point cur = q.front(); q.pop();
        int d = dist[cur.x][cur.y];

        // 이미 더 짧은 먹이 거리를 찾았으면 깊게는 안 내려감
        if (d > bestDist) continue;

        for (int i = 0; i < 4; ++i) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (dist[nx][ny] != -1) continue;
            if (board[nx][ny] > sharkSize) continue;

            dist[nx][ny] = d + 1;

            // 먹을 수 있는 물고기
            if (board[nx][ny] != 0 && board[nx][ny] < sharkSize) {
                if (dist[nx][ny] < bestDist) {
                    bestDist = dist[nx][ny];
                    candidates.clear();
                    Point p; p.x = nx; p.y = ny;
                    candidates.push_back(p);
                } else if (dist[nx][ny] == bestDist) {
                    Point p; p.x = nx; p.y = ny;
                    candidates.push_back(p);
                }
            }

            // 아직 찾은 최소 먹이 거리 이내라면 계속 확장
            if (dist[nx][ny] <= bestDist) {
                Point np; np.x = nx; np.y = ny;
                q.push(np);
            }
        }
    }

    if (candidates.empty()) {
        Point none; none.x = -1; none.y = -1;
        return make_pair(-1, none);
    }

    sort(candidates.begin(), candidates.end(), cmpPoint);
    return make_pair(bestDist, candidates.front());
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];
            if (board[i][j] == 9) {   // 상어 시작 위치
                shark.x = i; shark.y = j;
                board[i][j] = 0;      // 시작 칸은 빈 칸으로
            }
        }
    }
    
    while (1) {
        pair<int, Point> res = bfs(shark);
        int distToEat = res.first;
        Point target = res.second;

        if (distToEat == -1) break;      // 더는 먹을 물고기 없음

        totalTime += distToEat;           // 이동 시간 누적
        eaten += 1;                       // 한 마리 먹음
        shark = target;                   // 상어 위치 이동
        board[shark.x][shark.y] = 0;      // 먹은 칸 비우기

        if (eaten == sharkSize) {         // 성장
            sharkSize++;
            eaten = 0;
        }
    }

    cout << totalTime << '\n';
    return 0;
}
