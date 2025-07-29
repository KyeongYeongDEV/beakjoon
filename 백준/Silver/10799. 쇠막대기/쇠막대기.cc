#include <iostream>
#include <string>
using namespace std;

int main() {cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    string s;
    cin >>s;

    int result = 0;
    int openCount = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            openCount++;
        } else if (s[i] == ')') {
            openCount--;

            if (s[i - 1] == '(') {
                result += openCount;
            } else {
                result += 1;
            }
        }
    }

    cout << result << '\n';
}
