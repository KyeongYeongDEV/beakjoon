#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);

    int sum =0;
    vector<pair<int,int> > arr;
    vector<int> score;

    for(int i =0; i < 8; i++){
        int tmp;
        cin >> tmp;
        arr.push_back(make_pair(tmp,i+1));
    }
    
    sort(arr.begin(),arr.end());

    for(int i =7; i>=3; i--){
        score.push_back(arr[i].second);
        sum += arr[i].first;
    }

    sort(score.begin(),score.end());

    cout<< sum << "\n";
    for(int i =0 ; i < 5; i++){
        cout << score[i]<<" ";
    }
}