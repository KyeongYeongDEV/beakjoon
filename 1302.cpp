#include<iostream>
#include<map>
using namespace std;
//map을 이용하여 key값에 책이름을 넣고 value에 책수를 추가해주면 된다.

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);

    int num,cnt=0;
    cin >> num;
    map <string, int>m;

    while(num--){
        string name;
        cin >> name;
        m[name]++;
    }
    for(auto p : m){
        cnt = max(cnt,p.second);
    }
    for(auto p : m){
        if(p.second == cnt){
            cout << p.first;
            return 0;
        }
    }
}