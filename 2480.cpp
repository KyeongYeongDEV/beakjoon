#include<iostream>
using namespace std;

int main(){ cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int a,b,c;
    cin >> a>>b>>c;

    if(a == b && b == c){
        cout << 10000+(a*1000);
    }
    else if(a ==b){
        cout<< 1000 + (100 * a);
    }
    else if(b == c){
        cout<< 1000 + (100 * b);
    }
    else if(a == c){
        cout<< 1000 + (100 * c);
    }
    else{
        int max = a;
        if(max < b){max =b;}
        if(max <c){max = c;}
        cout << 100*max;
    }
}