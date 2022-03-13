#include<iostream>
using namespace std;

int main(){cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int x,y,w,h,min=1001;
    cin >> x>> y>> w>> h;

    if(w-x <min){ min = w-x;}
    if(h-y < min){ min = h-y;}
    if(x<min){min = x;}
    if(y<min){min = y;}

    cout << min;
}