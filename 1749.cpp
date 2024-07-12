#include<iostream>
using namespace std;

#define MAX 201

int main(){ cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int n, m, result = -99999;
    int arr[MAX][MAX] = {0,};
    int sum[MAX][MAX] = {0,};

    cin >> n >> m;

    for(int i=1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> arr[i][j];

            //전체 누적합
            sum[i][j] = arr[i][j] + sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1];
        }
    } 

    for(int i =1; i <= n; i++){
        for(int j =1; j <= m; j++){
            for(int x = 0; x < i; x++){
                for(int y = 0; y < j; y++){
                    //최대 부분행렬
                    result = max(result, sum[i][j] - sum[x][j] - sum[i][y] + sum[x][y]);
                }
            }
        }
    }

    cout << result;
}