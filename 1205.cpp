#include<iostream>
#include<vector>
using namespace std;
#define MAX 2000000001


int main(){ cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int N, score, P;
    vector<int>  v;

    cin >> N >> score >> P;

    for (int i =0; i < N; i++){
        int tmp; 
        cin >> tmp; 
        v.push_back(tmp);
    }

    int renk = 1;
    int cnt = 0;
    for(int i = 0; i < N; i++){
        if (v[i] > score){
            renk++;
        } else if (v[i] == score){
            renk = renk;
        }else break;
        cnt++;
    }

    if(cnt == P) renk = -1;
    if(N == 0) renk = 1;

    cout << renk << "\n";
}