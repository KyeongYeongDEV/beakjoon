#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n;
    cin >> n;

    vector<vector<int> > adj(n + 1);
    vector<int> in_degree(n + 1, 0);
    vector<int> task_time(n + 1, 0);
    vector<int> completion_time(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> task_time[i];

        int prereq_count;
        cin >> prereq_count;

        for (int j = 0; j < prereq_count; j++) {
            int prereq_task;
            cin >> prereq_task;
            adj[prereq_task].push_back(i);
            in_degree[i]++;
        }
    }

    // 3. 큐 초기화
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
            completion_time[i] = task_time[i]; // 선행 작업 없으면, 자신의 소요 시간이 곧 완료 시간
        }
    }

    // 4. 위상 정렬 및 DP 실행
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : adj[cur]) {
            completion_time[next] = max(completion_time[next], completion_time[cur] + task_time[next]);

            in_degree[next]--;
            if (in_degree[next] == 0) {
                q.push(next);
            }
        }
    }

    int max_time = 0;
    for (int i = 1; i <= n; i++) {
        if (completion_time[i] > max_time) {
            max_time = completion_time[i];
        }
    }

    cout << max_time << "\n";

    return 0;
}