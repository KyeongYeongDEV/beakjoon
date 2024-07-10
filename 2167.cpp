#include<iostream>
using namespace std;

#define MAX 301

int main(){ cout.tie(0); cin.tie(0); ios::sync_with_stdio(0);
    int arr[MAX][MAX] = {0,};
    int N ,M, K;

    cin >> N >> M;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> arr[i][j];
        }
    }

    cin >> K;
    for(int q=1; q <= K; q++){
        int i,j,x,y, sum =0;

        cin >> i >> j >> x >> y;

        for(int a = i; a <= x; a++){
            for(int b = j; b <= y; b++){
                sum += arr[a][b];
            }
        }
        cout << sum << "\n";
    }
}