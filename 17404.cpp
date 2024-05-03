#include<iostream>
#include<algorithm>
using namespace std;

int RGB[1001][3]= {0,};
int DP[1001][3]= {0,};
int n =0 ;

void input(){  
    cin >> n;

    for(int i=0; i < n; i++){
        cin >> RGB[i][0] >> RGB[i][1] >> RGB[i][2];
    } 
}

void solution(){
    int result = 987654321;

    for(int i=0 ; i < 3; i++){
        for(int j =0; j< 3; j++){
            if( i == j){
                DP[0][j] = RGB[0][j];
            }else{
                DP[0][j] = 987654321;
            }
        }

        for(int j = 1; j < n; j++){
            DP[j][0] = RGB[j][0] + min(DP[j-1][1], DP[j-1][2]);
            DP[j][1] = RGB[j][1] + min(DP[j-1][0], DP[j-1][2]);
            DP[j][2] = RGB[j][2] + min(DP[j-1][0], DP[j-1][1]);
        }

        for(int j=0; j < 3; j++){
            if( j == i) continue;
            result  = min(result, DP[n-1][j]);
        }
    }
    
    cout << result;
}

void solved(){
    input();
    solution();
}

int main(){ cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    solved();
}