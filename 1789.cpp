#include<iostream>
using namespace std;

int main(){cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    long long num,sum=0,cnt=0;
    cin >> num;

    for(int i=1; i <=num;i++){
        sum+=i;
        cnt++;
        if(sum == num){break;}
        else if(sum >num){cnt--; break;}
        
    }
    cout << cnt;
}