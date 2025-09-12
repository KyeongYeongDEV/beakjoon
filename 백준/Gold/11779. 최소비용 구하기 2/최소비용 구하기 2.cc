#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> 
#include <cstring>

using namespace std;

#define MAX 1001
#define INF 987654321

int n, m, START, END;
int dist[MAX];
int parent[MAX];
vector <pair<int, int> > graph[MAX];


void dijkstra() {
    fill(dist,dist + n + 1, INF);

    priority_queue <pair<int, int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
    dist[START] = 0;
    pq.push(make_pair(0, START));

    while (!pq.empty()) {
        int cur_cost = pq.top().first;
        int cur_city = pq.top().second;
        pq.pop();

        if (dist[cur_city] < cur_cost) {
            continue;
        }

        for (int i =0; i < graph[cur_city].size(); i++) {
            int next_city = graph[cur_city][i].first;
            int next_cost = graph[cur_city][i].second;

            // 경유하는 게 비용이 적다면
            if (cur_cost + next_cost < dist[next_city]) {
                dist[next_city] = cur_cost + next_cost;
                pq.push(make_pair(dist[next_city], next_city));
                parent[next_city] = cur_city;
            }
        }
    }
}

int main() {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from].push_back(make_pair( to, cost));
    }

    cin >> START >> END;

    dijkstra();

    cout << dist[END] << "\n";

    // 경로 역추척
    vector<int> path;
    int cur = END;
    while (cur != 0) {
        path.push_back(cur);
        cur = parent[cur]; // 부모 노드 따라 계속 이동
    }
    reverse(path.begin(), path.end());

    cout << path.size() << "\n";
    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << " ";
    }

}