#include<iostream>
using namespace std;

int DP[1001][4]= {0,};
int RGB[1001][4] = {0,};
int n=0, result = 0; 

int min(int a, int b){
    return a > b ? b : a;
}

void input(){
    cin >> n;

    for(int i=1; i <= n; i++){
        for(int j= 1; j <= 3; j++){
            cin >> RGB[i][j];
        }
    }
}

int solution(){
    DP[1][1] =  RGB[1][1];
    DP[1][2] =  RGB[1][2];
    DP[1][3] =  RGB[1][3];  

    for(int i =2; i <= n; i++){
        for(int j = 1; j <= 3; j++){
            if(j == 1){ //빨
                DP[i][1] = RGB[i][1] + min(DP[i-1][2], DP[i-1][3]);
            }else if(j == 2) { //초
                DP[i][2] = RGB[i][2] + min(DP[i-1][1], DP[i-1][3]);
            }else{ //파
                DP[i][3] = RGB[i][3] + min(DP[i-1][1], DP[i-1][2]);
            }
        }
    }
    int tmp1 = min(DP[n][1], DP[n][2]);
    int tmp2 = DP[n][3];
    result = tmp1 < tmp2 ? tmp1 : tmp2;

    return result;
}

int main(){
    input();
    cout << solution();
}