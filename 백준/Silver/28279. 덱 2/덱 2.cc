#include <iostream>
#include <deque>
using namespace std;

int main() {cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);

    deque<int> dq;
    int T = 0;
    int tmp = 0;
    cin >> T;

    while (T--) {
        int n = 0;
        cin >> n;

        if (n == 1) {
            cin >> tmp;
            dq.push_front(tmp);
        } else if (n == 2) {
            cin >> tmp;
            dq.push_back(tmp);
        } else if (n == 3) { // "빼고 출력이라는 말이 pop을 하는 거였음
            if (dq.empty()) {
                cout << "-1\n";
            } else {
                cout << dq.front() << '\n';
                dq.pop_front();
            }
        } else if (n == 4) {
            if (dq.empty()) {
                cout << "-1\n";
            } else {
                cout << dq.back() << '\n';
                dq.pop_back();
            }
        } else if (n == 5) {
            cout << dq.size() << '\n';
        } else if (n == 6) {
            cout << (dq.empty() ? 1 : 0) << '\n';
        } else if (n == 7) {
            if (!dq.empty()) {
                cout << dq.front() << '\n';
            } else {
                cout << "-1\n";
            }
        } else if (n == 8) {
            if (!dq.empty()) {
                cout << dq.back() << '\n';
            } else {
                cout << "-1\n";
            }
        }
    }
}
