#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 50001

int main(){cout.tie(0); cin.tie(0); ios::sync_with_stdio(0);
    int n;
    cin >> n;

    long long arr[MAX] = {0,};
    long long sum[MAX] = {0,};
    long long m = -987654321;
    
    for(int i =1; i <= n; i++){
        cin >> arr[i];
        sum[i] += sum[i -1] + arr[i];
    }

    for(int i =1; i <= n / 2 +1; i++){
        for(int j = 1; j <= n; j++){
            long long tmp = sum[j-1] - sum[i -1];
            m = max(m, min(tmp, sum[n] - tmp));
        }
    }

    cout << m;
}