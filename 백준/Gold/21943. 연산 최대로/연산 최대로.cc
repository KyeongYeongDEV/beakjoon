#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define INF 987654321
#define MAX 20


// 그룹을 Q + 1개로 나누고
// 그룹 안은 더하기, 밖은 곱하기한다.

int N, P, Q, ans = 0; // 숫자 개수, 더하기 개수, 곱하기 개수, 결과
int num[9];

int calc(vector<vector <int> > &groups) {
    int result = 1;
    for (auto &g : groups) { // groups = [ [1,2,4,5], [7] ]  이런 식으로 그룹이 들어가 있음
        int sum = 0;
        for (int x : g) sum += x; // 그룹 합
        result *= sum; // 그룹 곱
    }

    return result;
}

void dfs( int idx, int remain, vector<vector <int> > &groups ) {
    if (idx == N) {
        if (remain == 0) {
            ans = max( ans, calc(groups) );
        }
        return;
    }

    for (int i = 0; i < groups.size(); i++) {
        groups[i].push_back(num[idx]);
        dfs(idx + 1, remain, groups);
        groups[i].pop_back(); // 백 트래킹을 통해 다른 경우 탐색
    }
}


int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }
    cin >> P >> Q;

    vector<vector <int> > groups(Q + 1);

    dfs(0, 0, groups);

    cout << ans;
}
