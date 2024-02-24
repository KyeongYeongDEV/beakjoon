#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct Lecture{
    int start, end;
}Lecture;

bool cmp(Lecture a, Lecture b){
    return a.start < b.start;
}

int main(){cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int n, answer =0;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> q;
    vector<Lecture> v;

    for(int i =0; i< n; i++){
        Lecture tmp ;
        cin >> tmp.start >> tmp.end;

        v.push_back(tmp);
    }

    sort(v.begin(), v.end(), cmp);

    for(int i =0; i < v.size(); i++){
        if(!q.empty() && (v[i].start >= q.top())){
            q.pop();
        }
        else{
            answer++;
        }
        q.push(v[i].end);
    }
    cout << answer;
}