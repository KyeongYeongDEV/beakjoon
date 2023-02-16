#include<iostream>
#include<vector>
using namespace std;

vector<int> vec;
int n =0 , result =0;


void dfs(int cnt, int sum){
    if(cnt > n -1){
        result = max(result, sum);
        return ;
    }

    dfs(cnt +1 , sum);
    dfs(cnt + 2, sum + vec[cnt]);
}

int main(){cin.tie(0);cout.tie(0); ios::sync_with_stdio(0);
    cin >> n;
    vec.resize(n);
    for(int i =0 ; i < n; i++){
        cin >> vec[i] >> vec[i] >> vec[i];
    }

    dfs(0,0);

    cout<< result << endl;
}