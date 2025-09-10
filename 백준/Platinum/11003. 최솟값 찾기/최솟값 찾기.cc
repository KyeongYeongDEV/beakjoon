#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() { ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, l;
    cin  >> n >> l;

    // <값, 인덱스>
    deque<pair <int, int> > dq;

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;


        // 맨뒤에서부터 현재들어온 값보다 큰 값들 제거
        while (!dq.empty() && dq.back().first >= tmp) {
            dq.pop_back();
        }

        dq.push_back(make_pair(tmp, i));

        // 앞쪽에 오래된 인덱스 제거 (현재기준(i) l 범위 밖의 인데스 제거)
        if (dq.front().second <= i - l) {
            dq.pop_front();
        }

        cout << dq.front().first << " ";
    }

}