#include<iostream>
using namespace std;

#define MAX 100001

int main(){cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int n=0, m =0;
    int arr[MAX] = {0,};
    int sum[MAX] = {0,};

    cin >> n >> m;

    for(int i =0; i < n; i++){
        cin >> arr[i];
    }

    for(int i = 0 ; i < m; i++){
        int a,b,h;
        cin >> a >> b >> h;

        sum[a-1] += h;
        sum[b] -= h;
    }

    int result = 0;
    for(int i= 0; i < n; i++){
        result += sum[i];
        arr[i] += result;
        cout << arr[i] << " ";
    }
}