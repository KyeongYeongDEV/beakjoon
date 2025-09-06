#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX 32001

int n, m;
vector<int> graph[MAX];
int degree[MAX];

// 위상 정렬
void topologySort() {
    priority_queue<int, vector<int>, greater<int> > pq;

    for (int i = 1; i <= n; i++) {
        // 선행 과목이 없는 것을 pq에 넣는다
        if (degree[i] == 0) {
            pq.push(i);
        }
    }

    while (!pq.empty()) {
        int cur = pq.top();
        pq.pop();

        cout << cur << " ";

        // cur을 선행으로 가지는 노드들 처리
        for (int nextNode : graph[cur]) {
            degree[nextNode]--;

            // nextNode의 모든 선행과목이 해결되었다면 pq에 넣는다.
            if (degree[nextNode] == 0) {
                pq.push(nextNode);
            }
        }
    }
    cout << "\n";
}

int main() { ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> n >> m;

    for (int i =0; i< m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        degree[b]++;
    }

    topologySort();


}