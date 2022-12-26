#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){cout.tie(0);cin.tie(0); ios::sync_with_stdio(0);
    int tmp;
    cin >> tmp;
    int DP[1001];
    vector<int> vec;
    int result =0;

    for(int i = 0; i < tmp; i++){
        int t=0;
        cin >> t;
        vec.push_back(t);
        int maxDP =0;

        for(int j =0; j < vec.size(); j++){
            if(vec[i] > vec[j]){
                if(maxDP < DP[j]){
                    maxDP = DP[j];
                }
            }
        }
        DP[i] = maxDP +1;
        result = max(result, DP[i]);
    }
    cout << result;
}