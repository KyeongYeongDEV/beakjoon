#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u;
    int v;
    int cost;
};

bool compareEdges(const Edge &a, const Edge &b) {
    return a.cost < b.cost;
}


// 유니온 파인드
vector<int> parent;
int findParent(int x) {
    if (parent[x] == x) {
        return x; // x가 부모일 경우 자기자신이 루트
    }
    return parent[x] = findParent(parent[x]); // 루트 찾고 x를 루트로 연결 후 반환
}

bool uniteSets(int a, int b) {
    a  = findParent(a);
    b  = findParent(b);
    if (a != b) { // 두 개의 루트가 다르면, 서로 다른 집합이라는 뜻
        parent[b] = a; //b집합을 a집합과 합친다
        return true;
    }

    return false; // 이미 루트가 같기 때문에 합치치 않고 false 반환
}



int main() { ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m;
    cin >> n >> m;

    vector<char> school(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> school[i];
    }

    vector<Edge> edges;
    for (int i =0; i < m; i++) {
        int u, v, d;
        cin >> u >> v >> d;

        // 두 학교의 성별이 다를 때만 저장
        if (school[u] != school[v]) {
            Edge temp;
            temp.u = u;
            temp.v = v;
            temp.cost = d;
            edges.push_back(temp);
        }
    }

    // 크루스칼 : 간선들 오름차순 정렬
    sort(edges.begin(), edges.end(), compareEdges);

    parent.resize(n + 1); // 사이즈 재정의 안 해주면 0이라서 반복문이 안 돈다
    for (int i =1; i <= n; i++) {
        parent[i] = i; // 모든 노드가 자기 자신을 부모로 갖게 설정(독립집합)
    }

    long long total = 0;
    int selectedEdges = 0;

    // 크루스칼 : 사이클 없는 간선 선택
    for (int i = 0; i < edges.size(); ++i) {
        const Edge& edge = edges[i];

        if (uniteSets(edge.u, edge.v)) {

            total += edge.cost;
            selectedEdges++;
        }
    }

    //  MST는 항상 n-1 개의 정점을 가짐
    // 이것을 통해 모든 곳이 연결이 됐는지 확인한다.
    if (selectedEdges == n - 1) {
        cout << total << "\n";
    } else {
        cout << -1 << "\n";
    }
}