#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define MAX 51

int n, l, r;
int population[MAX][MAX];
bool visited[MAX][MAX];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void bfs() {
    int days = 0;
    while (true) {
        bool movement_occurred = false;
        memset(visited, false, sizeof(visited));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    queue<pair<int, int> > q;
                    vector<pair<int, int> > union_countries;

                    q.push(make_pair(i, j));
                    visited[i][j] = true;

                    union_countries.push_back(make_pair(i, j));
                    int population_sum = population[i][j];

                    while (!q.empty()) {
                        pair<int, int> cur = q.front();
                        q.pop();

                        for (int k = 0; k < 4; k++) {
                            int next_x = cur.first + dx[k];
                            int next_y = cur.second + dy[k];

                            if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= n) {
                                continue;
                            }
                            if (visited[next_x][next_y]) {
                                continue;
                            }

                            int diff = abs(population[cur.first][cur.second] - population[next_x][next_y]);
                            if (diff >= l && diff <= r) {
                                visited[next_x][next_y] = true;
                                q.push(make_pair(next_x, next_y));
                                union_countries.push_back(make_pair(next_x, next_y));
                                population_sum += population[next_x][next_y];
                            }
                        }
                    }

                    if (union_countries.size() > 1) {
                        movement_occurred = true;
                        int new_population = population_sum / union_countries.size();

                        for (int i =0; i < union_countries.size(); i++) {
                            int x = union_countries[i].first;
                            int y = union_countries[i].second;

                            population[x][y] = new_population;
                        }
                    }
                }
            }
        }
        if (!movement_occurred) break;
        days++;
    }
    cout << days << endl;
}

int main() {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> l >> r;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> population[i][j];
        }
    }

    bfs();
}