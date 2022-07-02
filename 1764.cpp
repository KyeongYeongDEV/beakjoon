#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){cout.tie(0); cin.tie(0); ios::sync_with_stdio(0);
    vector<string> result,str_N; //N = 기준, M = 비교
    string tmp;
    int N,M;

    cin>>N>>M;

    for(int i=0; i < N; i++){
        cin>>tmp;
        str_N.push_back(tmp);
    }
    sort(str_N.begin(), str_N.end());

    for(int i=0; i < M; i++){
        cin >> tmp;

        if(binary_search(str_N.begin(),str_N.end(),tmp)){
            result.push_back(tmp);
        }
    }
    
    sort(result.begin(),result.end());

    cout<< result.size()<<"\n";
    for(int i=0; i < result.size(); i++){
        cout << result[i] << "\n";
    }

    return 0;
}