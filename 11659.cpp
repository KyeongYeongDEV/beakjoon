#include<iostream>
using namespace std;
#define MAX 100001

int main(){cout.tie(0); cin.tie(0); ios::sync_with_stdio(0);
    int n , m;
    cin >> n >> m;

    int arr[MAX]={0,};
    int sum[MAX] = {0,};

    for(int i=1; i <= n; i++){
        cin >> arr[i];
        sum[i] += sum[i-1] + arr[i];
    }

    while(m--){
        int x,y;
        cin >> x >> y;

        cout << sum[y] - sum[x-1] << "\n";
    }
}