#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
int A[51][51]; // 각 칸의 물의 양
vector< pair<int, int> > clouds;

int dy[] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
int dx[] = {0, -1, -1, 0, 1, 1, 1, 0, -1};

bool simulateTurn() {
    // 이동 명령이 없으면 종료
    if (M-- <= 0) {
        return false;
    }

    int d,s;
    cin >> d >> s;

    bool had_cloud[51][51] = {false};

    // 모든 구름 이동
    for (int i = 0; i < clouds.size(); i++) {
        int y = clouds[i].first;
        int x = clouds[i].second;

        int move_y = (dy[d] * s) % N;
        int move_x = (dx[d] * s) % N;

        int ny = (y + move_y + N) % N;
        int nx = (x + move_x + N) % N;

        clouds[i] = make_pair(ny, nx);
    }

    // 비 내리고 구름 사라짐
    for (int i = 0; i < clouds.size(); i++) {
        int y = clouds[i].first;
        int x = clouds[i].second;
        A[y][x]++;
        had_cloud[y][x] = true;
    }

    // 물 복사 버그 마법
    for (int i = 0; i < clouds.size(); i++) {
        int y = clouds[i].first;
        int x = clouds[i].second;
        int water_count = 0;

        // 대각선 4방향 확인
        for (int dir = 2; dir <= 8; dir += 2) {
            int ny = y + dy[dir];
            int nx = x + dx[dir];

            if (ny >= 0 && ny < N && nx >= 0 && nx < N) {
                if (A[ny][nx] > 0) {
                    water_count++;
                }
            }
        }
        A[y][x] += water_count;
    }

    // 새로운 구름 생성
    vector<pair<int, int> > next_clouds;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            if (A[r][c] >= 2 && !had_cloud[r][c]) {
                next_clouds.push_back(make_pair(r, c));
                A[r][c] -= 2;
            }
        }
    }

    clouds = next_clouds;

    return true;
}

int main() {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }

    // 초기 구름 설정
    clouds.push_back(make_pair(N - 1, 0));
    clouds.push_back(make_pair(N - 1, 1));
    clouds.push_back(make_pair(N - 2, 0));
    clouds.push_back(make_pair(N - 2, 1));

    while (simulateTurn());

    // 최종 물의 양 계산
    int total_water = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            total_water += A[i][j];
        }
    }
    cout << total_water << endl;



    return 0;
}