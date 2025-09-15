#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() { ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int N, M;
    cin >> N >> M;

    vector<vector<int> > adj(N + 1);
    vector<int> inDegree(N + 1, 0);
    vector<int> result(N + 1, 1);

    for (int i = 0; i < M; ++i) {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
        inDegree[B]++;
    }

    queue<int> q;
    for (int i = 1; i <= N; ++i) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int next : adj[current]) {
            result[next] = max(result[next], result[current] + 1);

            inDegree[next]--;

            if (inDegree[next] == 0) {
                q.push(next);
            }
        }
    }

    for (int i = 1; i <= N; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}