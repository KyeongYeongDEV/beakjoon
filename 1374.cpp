#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int main(){cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int n, room, from, to, answer =1;

    vector<pair < int, int>> v;
    priority_queue<int, vector<int>, greater<int> > lastTime;

    cin >> n;

    for(int i=0; i< n; i++){
        cin >> room >> from >> to;
        v.push_back({from, to});
    }
    sort(v.begin(), v.end());
    
    for(int i=0 ; i < v.size(); i++){
        int startTime = v[i].first;
        int endTime = v[i].second;

        if(lastTime.empty()){
            lastTime.push(endTime);
        }else{
            if(lastTime.top() > startTime){
                answer++;
            }
            else{
                lastTime.pop();
            }
            lastTime.push(endTime);
        }
    }
    cout << answer;
}