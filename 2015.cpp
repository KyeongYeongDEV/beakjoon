#include<iostream>
#include<map>
using namespace std;

#define MAX 200001

long long n, k, result =0;
long long arr[MAX] = {0,};

map<long long, long long > m;

int main(){ cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n >> k;

    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        arr[i] += arr[i-1];
        if(arr[i] == k) result++;
    }

    for(int i=1; i <= n; i++){
        result += m[arr[i] - k];
        m[arr[i]]++;
    }

    cout << result;
}