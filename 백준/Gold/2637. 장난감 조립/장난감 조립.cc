#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector< pair<long, long> > adj[n + 1];
    vector<long long> degree(n + 1, 0);
    vector<long long> needs(n + 1, 0); // DP

    for (int i =1; i <= m; i++) {
        int x, y, k;
        cin >> x >> y >> k; // x에 y가 x개 필요

        adj[x].push_back(make_pair(y, k));
        degree[y]++;
    }

    queue<int> q;
    q.push(n);
    needs[n] = 1;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        // 완성품 -> 중간부품 -> 기본부품 순으로 개수 DP
        for (auto &prev : adj[cur]) {
            long long prev_part = prev.first;
            long long quantity = prev.second;

            needs[prev_part] += needs[cur] * quantity;

            degree[prev_part]--;

            if (degree[prev_part] == 0) {
                q.push(prev_part);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        // 기본 부품은 adj 리스트가 비어있음
        if (adj[i].empty()) {
            cout << i << " " << needs[i] << "\n";
        }
    }
}