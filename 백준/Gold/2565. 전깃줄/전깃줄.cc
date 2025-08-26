#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() { ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;

    vector< pair<int,int> > v;

    for (int i = 0; i < n; i++) {
        int x,y;
        cin >> x >> y;
        v.push_back(make_pair(x,y));
    }

    sort(v.begin(), v.end());

    vector<int> LIS;

    for (int i = 0; i < n; i++) {
        int b = v[i].second;

        //b가 들어갈 자리를 이진 탐색으로 찾음
        auto it = lower_bound(LIS.begin(), LIS.end(), b);
        if (it == LIS.end()) {
            // b가 LIS의 모든 값보다 크면
            // 증가 수열을 늘릴 수 없으므로 맨 뒤에 추가
            LIS.push_back(b);
        }
        else {
            // b를 넣을 자리가 LIS 안에 이미 있다면
            // 해당 위치의 값을 b로 교체
            *it = b;
        }
    }

    cout << n - (int)LIS.size() << "\n";

}