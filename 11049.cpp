#include<iostream>
using namespace std;

#define MAX 510

int main(){
    int n = 0;
    int matrix[MAX][2] = {0,};
    int dp[MAX][MAX] ={0,};

    cin >> n;

    for(int i =1; i <= n; i++){
        cin >> matrix[i][0] >> matrix[i][1];
    }
    
    for(int i =1; i <= n; i++){
        for(int j = 1; i+j <= n; j++){
            dp[j][i+j] = 987654321;
            
            for(int k = j; k <= i+j; k++){
                dp[j][i+j] = min(dp[j][i+j], dp[j][k] + dp[k+1][i+j] + matrix[j][0] * matrix[k][1] * matrix[i+j][1]);
            }
        }
    }
    
    cout << dp[1][n];

}