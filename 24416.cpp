#include<iostream>
using namespace std;

int arr[41] = {0,};
int cnt1 =0, cnt2 =0;

int fibo(int n){
    if(n ==1 || n == 2){
        cnt1++;
        return 1;
    }else return ((fibo(n-1) + fibo(n-2)));
} 

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int n =0;
    cin >> n;

    fibo(n);

    arr[1]=1; arr[2] =1;
    for(int i=3; i <= n; i++){
        arr[i] = arr[i-1] + arr[i-2];
        cnt2++;
    }
    cout << cnt1 << " " << cnt2;
}