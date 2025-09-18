#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N;
    cin >> N;

    vector<vector<int> > adj(N + 1);
    vector<int> dist(N + 1, 0);
    vector<int> value(N + 1);
    vector<int> result(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        cin >> value[i];

        int prereq;
        while (true) {
            cin >> prereq;
            if (prereq == -1) break;

            adj[prereq].push_back(i);
            dist[i]++;
        }
    }

    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (dist[i] == 0) {
            q.push(i);

            result[i] = value[i];
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : adj[cur]) {
            result[next] = max(result[next], result[cur] + value[next]);

            dist[next]--;

            if (dist[next] == 0) {
                q.push(next);
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << result[i] << "\n";
    }
}