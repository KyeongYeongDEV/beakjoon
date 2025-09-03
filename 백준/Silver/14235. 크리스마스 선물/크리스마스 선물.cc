#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() { ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;

    priority_queue<int> q;

    while (n--) {
        int a;
        cin >> a;

        if (a == 0) {
            if (q.empty()) {
                cout << -1 << '\n';
            } else {
                cout << q.top() << '\n';
                q.pop();
            }
        } else {
            for (int i =0; i < a; i++) {
                int num;
                cin >> num;
                q.push(num);
            }
        }
    }
}