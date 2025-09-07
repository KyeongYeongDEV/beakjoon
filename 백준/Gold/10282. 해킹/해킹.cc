#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX 10001
#define INF 987654321

int testCase;
int n, d, c; // 컴터 개수, 의존성 개수, 해킹당한 컴터 수
vector<pair<int, int> >graph[MAX];
int dist[MAX];

void dijkstra(int start) {
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }

    // 최소힙
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

    dist[start] = 0;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        int curTime= pq.top().first;
        int curNode= pq.top().second;
        pq.pop();

        // 이미 처리된 노드는 무시
        if (dist[curNode] < curTime) continue;


        // 현재 노드에서 연결된 컴터들 확인
        for (int i = 0; i  < graph[curNode].size(); i++) {
            int nextNode = graph[curNode][i].second;
            int timeToNext = graph[curNode][i].first;

            // 새로운 경로가 기존 경로보다 짧다면 갱신
            if (dist[nextNode] > dist[curNode] + timeToNext) {
                dist[nextNode] = dist[curNode] + timeToNext;
                pq.push(make_pair(dist[nextNode], nextNode));
            }
        }
    }
}

int main() { ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> testCase;

    while (testCase--) {
        cin >> n >> d >> c;

        for (int i = 1;  i <= n; i++) {
            graph[i].clear();
        }

        for (int i = 0; i < d; i++) {
            int a, b, s;
            cin >>  a >> b >> s;

            graph[b].push_back(make_pair(s, a));
        }

        dijkstra(c);

        int totalCount = 0;
        int maxTime = 0;

        for (int i = 1; i <= n; i++) {
            if (dist[i] != INF) {
                totalCount++;
                maxTime = max(maxTime, dist[i]);
            }
        }

        cout << totalCount << " " << maxTime << "\n";
    }
}