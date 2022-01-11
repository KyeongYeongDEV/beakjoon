#include<iostream>
using namespace std;

int main(){
    int num,sum =0, a,b;
    cin >> num;

    for(int i =0 ; i <num; i++){
        cin >>a>>b;
        sum += b%a;
    }

    cout << sum;
}