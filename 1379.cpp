#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

struct cmp{
    bool operator()(pair<int, pair < int, int>> a, pair<int, pair < int, int>> b){
        return a.second.second > b.second.second;
    }
};

bool comp(pair<int, pair < int, int>> a, pair<int, pair < int, int>> b){
    return a.second.first < b.second.first;
}

int main(){cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int n, room, from, to, answer = 0;
    cin >> n;

    vector<int> r(n,0);
    vector<pair<int, pair < int, int>> > v;
    priority_queue<pair<int, pair < int, int>>, vector<pair<int, pair < int, int>> >, cmp > lastTime;

    for(int i=0; i< n; i++){
        cin >> room >> from >> to;
        v.push_back({room, {from, to}});
    }
    sort(v.begin(), v.end(), comp);
    
    for(int i=0 ; i < v.size(); i++){
        int startTime = v[i].second.first;
        int endTime = v[i].second.second;

        if(!lastTime.empty() && (lastTime.top().second.second <= startTime)){
            r[v[i].first-1] = r[lastTime.top().first-1];
            lastTime.pop();
        }
        else {
            answer++;
            r[v[i].first-1] = answer;
        }
        lastTime.push(v[i]);
    }
    cout << answer << "\n";
    for(int i=0; i < r.size(); i++){
        cout << r[i] << "\n";
    }
} 