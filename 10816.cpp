#include<iostream>
#include<map>
using namespace std;

int main(){cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int num,tmp;
    map<int,int> m;
    cin >>num;

    for(int i =0; i < num; i++){
        cin >> tmp;
        m[tmp]++;
    }

    cin >> num;
    for(int i =0; i<num; i++){
        cin >>tmp;
        cout << m[tmp]<< " ";
    }
}