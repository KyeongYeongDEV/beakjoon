#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


int grid[4][4]; // 현재 물고기 번호
int fish_dir[17]; // 각 물고기의 현재 방향
pair<int, int> fish_pos[17]; // 각 물고기의 현재 (x, y) 위치
int shark_x, shark_y; // 상어 현재 위치
int max_score = 0; // 최종 출력 점수

// 문제랑 이동 방향 맞춤
int dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};


void dfs(int score) {
    // 최대점수 갱신
    max_score = max(max_score, score);

    // 현재 상태 저장, 백트래킹용
    int temp_grid[4][4];
    int temp_fish_dir[17];
    pair<int, int> temp_fish_pos[17];

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            temp_grid[i][j] = grid[i][j];
        }
    }

    for (int i = 1; i <=16; i++) {
        temp_fish_dir[i] = fish_dir[i];
        temp_fish_pos[i] = fish_pos[i];
    }

    // 모든 물고기 이동
    for (int i = 1; i <= 16; i++) {
        // 먹힌 물고기 패스
        if (fish_pos[i].first == -1) continue;

        int x = fish_pos[i].first;
        int y = fish_pos[i].second;
        int dir = fish_dir[i];

        for (int j = 0; j < 8; j++) {
            int next_dir = (dir + j) % 8;
            int nx = x + dx[next_dir];
            int ny = y + dy[next_dir];

            // 칸 밖으로 나가거나 상어가 잇다면 패스
            if (ny < 0 || ny >= 4 || nx < 0 || nx >= 4 || (ny == shark_y && nx == shark_x)) {
                continue;;
            }

            // 물고기 스왑
            int target_fish_num = grid[ny][nx];
            grid[y][x] = target_fish_num;
            grid[ny][nx] = i;


            if (target_fish_num != 0) {
                fish_pos[target_fish_num] = make_pair(x, y);
            }

            fish_pos[i] = make_pair(nx, ny);
            fish_dir[i] = next_dir;

            break;
        }
    }

    // 상어 이동
    int shark_dir = fish_dir[0];
    for (int i = 1; i <= 3; ++i) {
        int nx = shark_x + dx[shark_dir] * i;
        int ny = shark_y + dy[shark_dir] * i;

        if (ny < 0 || ny >= 4 || nx < 0 || nx >= 4) break;
        if (grid[ny][nx] == 0) continue;

        int eaten_fish_num = grid[ny][nx]; // 먹은 물고기 점수
        int new_score = score + eaten_fish_num;

        int prev_shark_x = shark_x;
        int prev_shark_y = shark_y;

        // 상어 이동
        shark_x = nx;
        shark_y = ny;
        fish_dir[0] = fish_dir[eaten_fish_num];
        fish_pos[eaten_fish_num] = make_pair(-1, -1);
        grid[ny][nx] = 0;

        dfs(new_score);

        // 이전 상태로 돌리기(백트래킹)
        grid[ny][nx] = eaten_fish_num;
        fish_pos[eaten_fish_num] = make_pair(nx, ny);
        fish_dir[0] = shark_dir;
        shark_x = prev_shark_x;
        shark_y = prev_shark_y;
    }

    // 물고기 이동상태 복원
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            grid[i][j] = temp_grid[i][j];

    for(int i = 1; i <= 16; i++) {
        fish_dir[i] = temp_fish_dir[i];
        fish_pos[i] = temp_fish_pos[i];
    }
}


int main() {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            int num, dir;
            cin >> num >> dir;

            grid[i][j] = num;

            fish_dir[num] = dir - 1;
            fish_pos[num] = make_pair(j, i);
        }
    }
    int start_score = grid[0][0];
    int start_shark_dir = fish_dir[start_score];

    shark_x = 0;
    shark_y = 0;

    fish_dir[0] = start_shark_dir;

    fish_pos[start_score] = make_pair(-1, -1);
    grid[0][0] = 0;

    dfs(start_score);

    cout << max_score << "\n";

}