#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int arr[1001], DP[1001], res[1001], n = 0;

void input(){
    cin >> n;

    for(int i=1; i <= n;  i++){
        cin >> arr[i];
    }
}


void print(int i){
    if(res[i] != 0){
        print(res[i]);
    }
    cout << arr[i] <<  ' ';
}
void solution(){
    DP[1] = 1;
    for(int i = 2; i <= n; i++){
        DP[i] =1;

        int idx = 0;
        for(int j = i-1; j > 0 ; j--){
            if(arr[i] > arr[j] && DP[j] +1 > DP[i]){
                DP[i] = DP[j] +1;
                idx = j;
            }
        }
        res[i] = idx;
    }

    int ans = 0;
    int idx = 0;

    for(int i = 1; i <= n; i++){
        if(DP[i] > ans){
            ans = DP[i];
            idx = i;
        }
    }

    cout << ans << "\n";
    print(idx);
}

void solved(){
    input();
    solution();
}

int main(){ cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    solved();
}
