#include <iostream>
#include <deque>
#include <sstream>
using namespace std;

deque<int> parseArray(const string &input) {
    deque<int> result;
    string num;
    for (char ch : input) {
        if (isdigit(ch)) {
            num += ch;
        } else if (!num.empty()) {
            result.push_back(stoi(num));
            num.clear();
        }
    }

    return result;
}

int main() {cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int T = 0;
    cin >> T;

    while (T--) {
        string p = "", input = ""; // R | D // 초기 배열
        int n = 0; // 초기 배열 수
        int isReversed = 0;
        int isError = 0;
        cin >> p >> n >> input;

        deque<int> dq = parseArray(input);

        for (char cmd : p) {
            if (cmd == 'R') {
                isReversed = !isReversed;
            } else if (cmd == 'D') {
                if (dq.empty()) {
                    isError = 1;
                    break;
                }

                if (isReversed) dq.pop_back();
                else dq.pop_front();
            }
        }

        if (isError) {
            cout << "error\n";
        } else {
            cout << "[";
            if (isReversed) {
                for (int i = dq.size() - 1; i >= 0; i--) {
                    cout << dq[i];
                    if (i != 0 ) cout << ",";
                }
            }
            else {
                for (int i =0; i < dq.size(); i++) {
                    cout << dq[i];
                    if (i != dq.size() - 1) cout << ",";
                }
            }
            cout << "]\n";
        }

    }
}