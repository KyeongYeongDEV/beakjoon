#include<iostream>
using namespace std;

int main(){ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    int n,m,num;
    int DP[33][33] = {0};
    cin >>  num;

    while(num--){
        cin>>n >> m;

        for(int i = 1; i <=m; i++){
            DP[1][i] = i;
        }
        for(int i=2; i <=n; i++){
            for(int j =2; j <=m; j++){
                DP[i][j] = DP[i-1][j-1] + DP[i][j-1];
            }
        }
        cout<< DP[n][m] <<endl;
    }
}