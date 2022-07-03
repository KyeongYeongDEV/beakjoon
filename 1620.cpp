#include<iostream>
#include<map>
using namespace std;

int main(){cout.tie(0); cin.tie(0); ios::sync_with_stdio(0);
    map<string , int> m;
    string arr[100001];
    int N,M;
    string s_tmp;

    cin >> N>>M;

    for(int i =1; i <= N; i++){ //저장
        cin >> s_tmp;
        arr[i] = s_tmp;
        m[s_tmp] = i;
    }

    for(int i =0 ; i < M; i++){
        cin >>s_tmp;

        if(isdigit(s_tmp[0])){//숫자이면
            int num = stoi(s_tmp);
            cout << arr[num] << "\n";
        }else{
            cout<< m[s_tmp] << "\n";
        }
    }
}