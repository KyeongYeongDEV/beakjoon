#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() { ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int N, M; // 학생수, 키 비교 횟수
    cin >> N >> M;


    vector<vector<int> > adj(N+1);
    vector<int> dist(N+1);
    vector<int> result;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        dist[b]++;
    }

    queue<int> q;

    for (int i = 1; i <= N; i++) {
        if (dist[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        result.push_back(cur);

        for (int next : adj[cur]) {
            dist[next]--;

            if (dist[next] == 0) {
                q.push(next);
            }
        }
    }

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

}