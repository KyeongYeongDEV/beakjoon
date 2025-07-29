#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    int N =0;
    cin>>N;

    while(N--) {
        int N,M;
        cin >> N >> M;

        queue<pair<int, int> > q;
        vector<int> priorities;

        for (int i = 0; i < N; i++) {
            int tmp;
            cin >>tmp;

            q.push(make_pair(i,tmp));
            priorities.push_back(tmp);
        }

        sort(priorities.begin(),priorities.end(), greater<int>()); // 중요도 기준 내림차순

        int cnt =0;
        int idx = 0;

        while(!q.empty()) {
            int curIndex = q.front().first;
            int curPriority = q.front().second;
            q.pop();

            if (curPriority == priorities[idx]) {
                cnt++;
                if (curIndex == M) {
                    cout<<cnt<<'\n';
                    break;
                }
                idx++;
            } else {
                q.push(make_pair(curIndex,curPriority));
            }
        }
    }

}
