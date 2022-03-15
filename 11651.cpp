#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool compare(pair<int,int>a, pair<int,int>b){
    if(a.second == b.second){
        return a.first <b.first;
    }
    else{
        return a.second < b.second;
    }
}

int main(){cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int num,first,second;
    cin >> num;
    vector< pair<int,int> > vec;

    for(int i=0; i<num; i++){//입력
        cin >>first >> second;
        vec.push_back(make_pair(first,second));
    }

    sort(vec.begin(),vec.end(),compare);

    for(int i=0; i <num; i++){
        cout << vec[i].first << " "<<vec[i].second<<"\n";
    }
}