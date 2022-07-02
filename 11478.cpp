#include<iostream>
#include<set>
using namespace std;

int main(){cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    set<string> s;
    string str,s_tmp;

    cin >> str;

    for(int i =0; i < str.length(); i++){
        for(int j = i; j< str.length(); j++){
            s_tmp += str[j];
            s.insert(s_tmp);
        }
        s_tmp = "";
    }

    cout << s.size();

    return 0;
}