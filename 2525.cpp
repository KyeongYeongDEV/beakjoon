#include<iostream>
using namespace std;

int main(){ cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int a,b,c;
    cin >> a>>b>>c;

    b += c;
    if(b >59){
        while(b > 59){
            b -= 60;
            a++;
        }
    }
    
    if(a >= 24){
        a-= 24;
    }
    cout << a << " "<<b;
}