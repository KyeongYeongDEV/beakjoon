#include<iostream>
using namespace std;
//처음에는 그냥 재귀로 풀었는데 시간초과가 나왔다
//찾아보니 DP(다이나믹 프로그래밍) 메모이제이션으로 풀어야 한다더라 
//DP 공부를 해야 할 것 같다

int dp[41]={0};

int fibo(int n){
    if(n <= 0){ dp[0] = 0; return 0; }
    else if(n ==1){ dp[1] = 1; return 1; }

    if(dp[n] != 0){ // 계산된 값 
        return dp[n]; 
    } 
    else { 
        return dp[n] = fibo(n-1) + fibo(n-2);
    }
}

int main(){cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int num;
    cin >>num;

    while(num--){
        int a;
        cin >> a;
        
        if(a == 0){ cout << "1 0\n";}
        else if(a ==1){cout << "0 1\n";}
        else{
            fibo(a);
            cout << dp[a-1]<<" "<<dp[a] <<"\n";
        }
    }
}