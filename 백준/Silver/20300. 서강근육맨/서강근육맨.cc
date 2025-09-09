#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() { ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;

    vector<long long> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    long long result = 0;
    if (n % 2 != 0) {
        result = v[n-1];
        n--;
    }

    for ( int i = 0; i < n / 2; i++ ) {
        long long tmp = v[i] + v[n - 1 - i];

        if (tmp > result) {
            result = tmp;
        }
    }

    cout << result;


}