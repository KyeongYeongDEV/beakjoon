#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

#define MAX_DAY 10001
using namespace std;

int main(){cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    priority_queue<int, vector<int>, greater<int>> q;
    vector< pair<int, int>> v;

    int n;
    cin >> n;

    for(int i=0; i < n; i++){
        int p,d;
        cin >> p >> d;
        v.push_back({d,p});
    }

    sort(v.begin(), v.end());

    for(int i=0; i < n ; i++){
        q.push(v[i].second);
        
        if(q.size() > v[i].first){
            q.pop();
        }
    }

    int result =0;
    while(!q.empty()){
        result += q.top();
        q.pop();
    }

    cout << result;
    
}