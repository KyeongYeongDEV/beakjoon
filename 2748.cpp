#include<iostream>
using namespace std;

int main(){
    long int num, a = 0, b = 1, tmp=0; 
    cin >> num;

    for(int i=1; i <num; i++){
        tmp = b;
        b =  b+a;
        a = tmp;
    }

    cout << b;
}