#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

// 입력된 값이 0이 아니라면 배열에 추가하고
// 0이라면 배열에서 절대값이 가장 작은 값을 출력하고 | 그 값을 배열에서 제거한다.

struct compare {
    bool operator()(int a, int b) {
        if (abs(a) == abs(b)) {
            return a > b; // 절대값이 같으면 실제 값이 작은 게 우선
        }
        return abs(a) > abs(b); // 절대값 작은 게 우선
    }
};

int main() {cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    int N =0;
    cin>>N;
    priority_queue<int, vector<int>, compare> pq;

    while (N--) {
        int tmp = 0;
        cin >> tmp;

        if (tmp != 0) {
            pq.push(tmp);
        } else {
            if (pq.empty()) {
                cout << 0 << '\n';
            } else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
    }
}
