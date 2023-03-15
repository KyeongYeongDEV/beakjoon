#include<iostream>
using namespace std;

int main(){cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int x = 0;
    cin >> x;

    int dp[x];
    dp[1] = 0;

    for(int i= 2; i <= x; i++){
        // 문제에서는 순서가 3나누고 2나누고 1빼는 순서인데
        // 그렇게 하면 오탑이 나온다
        dp[i] = dp[i-1]+1;
        if(!(i%2)){
            dp[i] = min(dp[i],dp[i/2]+1);
        }
        if(!(i%3)){
            dp[i] = min(dp[i], dp[i/3]+1);
        }
    }
    cout << dp[x];
}