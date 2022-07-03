#include<iostream>
#include<map>
using namespace std;

int main(){
    int N,M,cnt=0;
    cin >> N>>M;
    map<string, bool> m;
    string str_tmp;

    for(int i=0; i < N; i++){
        cin >> str_tmp;
        m[str_tmp] = true;
    }
    for(int i=0; i < M; i++){
        cin >> str_tmp;
        if(m[str_tmp]){cnt++;}
    }
    cout << cnt;
}