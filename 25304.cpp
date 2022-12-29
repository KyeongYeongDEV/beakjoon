#include<iostream>  
using namespace std;

int main(){cout.tie(0); cin.tie(0); ios::sync_with_stdio(0);
    int X=0; //총 금액
    int N = 0; // 물건의 종류 수
    
    cin >> X >> N;

    for(int i =0; i < N; i++){
        int tmp1 = 0, tmp2 = 0;
        cin >> tmp1 >> tmp2;

        X -= tmp1 * tmp2;
    }
    if(X == 0) cout << "Yes";
    else cout << "No";
}