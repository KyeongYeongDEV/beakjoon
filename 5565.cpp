#include<iostream>
using namespace std;

int main(){
    int hap,tmp;
    cin >> hap;

    for(int i = 1; i<10;i++){
        cin >> tmp;
        hap -= tmp;
    }
    cout << hap;
}