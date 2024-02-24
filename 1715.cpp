#include<iostream>
#include<queue>

using namespace std;

int main(){cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> q;

    for(int i=0; i< n; i++){
        int tmp;
        cin >> tmp;

        q.push(tmp);
    }
    
    int result =0;
    while(q.size() > 1){
        int first = q.top(); 
        int second = q.top();
        q.pop();

        result += first +  second;

        q.push(first + second); 
    }
    
    cout << result; 
}