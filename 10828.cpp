#include<iostream>
#include<stack>
using namespace std;

int main(){cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int num=0,tmp2=0;
    stack<int> s;
    string str="";
    cin >> num;

    while(num--){
        cin >> str;
        if(str == "push"){
            cin >> tmp2;
            s.push(tmp2);
        }else if(str == "pop"){
            if(s.empty()){cout << -1<<"\n";}
            else{
                cout << s.top()<<"\n";
                s.pop();}
        }else if(str == "size"){
            cout << s.size()<<"\n";
        }else if(str == "empty"){
            if(s.empty()){cout << 1<<"\n";}
            else {cout << 0<<"\n";}
        }else if(str == "top"){
            if(s.size() ==0){cout << -1 << "\n";}
            else{cout << s.top()<< "\n";}            
        }
    }
}