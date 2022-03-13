#include<iostream>
using namespace std;

int main(){
    while(1){
        int a,b,c;
        cin >> a>> b>> c;

        if(a ==0 && b ==0 && c ==0){break; }

        if(a>b){
            int tmp; 
            tmp =a;
            a= b;
            b=tmp;
        }
        if(b>c){
            int tmp;
            tmp =b;
            b =c;
            c =tmp;
        }
        if(a*a + b*b == c*c){cout << "right\n";}
        else{cout << "wrong\n";}
    }
}