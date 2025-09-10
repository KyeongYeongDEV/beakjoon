#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() { ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m;
    cin >> n >> m;

    int result = 0;
    vector<int> multi_10;
    vector<int> other;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;

        if (tmp == 10) {
            result++;
        } else if (tmp % 10 == 0) {
            multi_10.push_back(tmp);
        } else {
            other.push_back(tmp);
        }
    }

    sort(multi_10.begin(), multi_10.end());
    sort(other.begin(), other.end());

    for (int cake : multi_10) {
        if (m <= 0) break;

        int pieces = cake / 10;
        int need_cut = pieces - 1;

        if (m >= need_cut) {
            m -= need_cut;
            result += pieces;
        } else {
            result += m;
            m = 0;
        }

    }

    for (int cake : other) {
        if (m <= 0) break;

        int pieces = cake / 10;
        int need_cut = pieces;

        if (m >= need_cut) {
            m -= need_cut;
            result += pieces;
        } else {
            result += m;
            m = 0;
        }
    }

    cout << result;
}