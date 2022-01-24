#include<iostream>
using namespace std;

int main(){cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int E,S,M,res=0,year=1;
    cin >> E>> S>> M;

    while(1){
        if((year-E)%15 ==0 && (year-S)%28 ==0 && (year-M) %19 ==0){
            res = year;
            break;
        }
        year++;
    }
    cout<< res;
}