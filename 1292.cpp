#include<iostream>
using namespace std;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);

    int a,b,sum=0,cnt =0;
    cin >> a>>b;

    for(int i= 1; i <=b; i++){
        for(int j = 1; j <= i; j++){
            cnt++;
            if(cnt >= a && cnt <= b){
                sum +=i;
            }
            if(cnt == b){
               break;
            }
        }
        if(cnt == b){
               break;
        }
    }
    cout << sum;
}