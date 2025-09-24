#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

 int n;
 cin >> n;

 long long dp[11];

 dp[1] = 1;
 dp[2] = 2;
 dp[3] = 4;

 for (int i = 4; i <= 11; i++) {
  dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
 }

 while (n--) {
  int tmp;
  cin >> tmp;

  cout << dp[tmp] << "\n";
 }
}