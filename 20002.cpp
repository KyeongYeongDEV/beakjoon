#include<iostream>
using namespace std;

int main(){ cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int n = 0, result = -999999;
    int arr[301][301] = {0,};
    int sum[301][301] = {0,};
    cin >> n;

    for(int i = 1; i <=n; i++){
        for(int j=1 ; j <= n; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 1; i <= n; i++){ // 누적합
        for(int j= 1; j <= n; j++){
            sum[i][j] = arr[i][j] + sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1];
        }
    }

    for(int x =1; x <= n; x++){ //최대값 계산
        for(int y = 1; y <= n; y++){
            // min(현재 행에서 마지막 행까지 남은 거리, 현재 열에서 마지막 열까지 남은 거리)
            // 즉, 가장 큰 정사각형
            int m = min(n - x, n - y); 

            for(int k = 0; k <= m; k++){
                //현재 x,y 를 기준으로 k *k 의 정사각형 계산
                int tmp = sum[x+k][y+k] - sum[x-1][y+k] - sum[x+k][y-1] + sum[x-1][y-1];
                result = max(result, tmp);
            }
        }
    }

    cout << result;
}