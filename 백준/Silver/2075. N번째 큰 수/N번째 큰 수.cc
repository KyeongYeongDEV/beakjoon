#include <iostream>
#include <queue>
using namespace std;

int main() { ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int> > pq;

    for (int i = 0; i < n; i++) {
        for (int j =0; j<n; j++) {
            int tmp ;
            cin >> tmp;

            pq.push(tmp);

            // 모든 값을 다 가지고 있을 필요 없이
            // n개의 수만 저장하고 있으면 됨
            if (pq.size() > n) pq.pop();
        }
    }
    // 최소힙이기 때문에 n개의 수중 n번째 큰수는 top에 있다.
    cout << pq.top() << '\n';
}