#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m;
    cin >> n >> m;


    vector<vector<int> > adj(n+1);
    vector<int> indegree(n+1);
    vector<int> result;

    for (int i = 0; i < m; i++) {
        int cnt;
        cin >> cnt;

        if (cnt == 0) continue;

        int prev;
        cin >> prev;


        for (int j = 1; j < cnt; j++) {
            int cur;
            cin >> cur;

            adj[prev].push_back(cur);
            indegree[cur]++;
            prev = cur;
        }
    }

    queue<int> q;
     for (int i = 1; i <= n; i++) {
         if (indegree[i] == 0) {
             q.push(i);
         }
     }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        result.push_back(cur);

        for ( int next : adj[cur] ) {
            indegree[next]--;
            if (indegree[next] == 0) {
                q.push(next);
            }
        }
    }

    if (result.size() != n) {
        cout << "0\n";
        return 0;
    }

    for (int i = 0; i < n; i++) {
        cout << result[i] << "\n";
    }
}