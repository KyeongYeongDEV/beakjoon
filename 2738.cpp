#include<iostream>
using namespace std;

int main(){cin.tie(0); cout.tie(0);
    int N=0,M=0;
    cin >>N>>M;

    int A[N][M];
    int B[N][M];
    int result[N][M];
    
    for(int i =0; i <N; i++){
        for(int j =0; j< M; j++){
            cin >> A[i][j];
        }
    }
    for(int i =0; i <N; i++){
        for(int j =0; j< M; j++){
            cin >> B[i][j];
            cout << A[i][j] + B[i][j] << " ";
        }cout << "\n";
    }
}