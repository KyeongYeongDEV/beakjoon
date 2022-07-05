#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int num;
    cin>> num;
    vector<int> vec(num);
    
    for(int i=0; i < num; i++){
        cin>>vec[i];
    }

    vector<int> cpy_vec(vec);
    sort(cpy_vec.begin(),cpy_vec.end());
    cpy_vec.erase(unique(cpy_vec.begin(),cpy_vec.end()),cpy_vec.end());

    for(int i=0; i < num; i++);
    for(int i=0; i< num; i++){
        auto it = lower_bound(cpy_vec.begin(),cpy_vec.end(),vec[i]);
        cout<< it - cpy_vec.begin()<<' ';
    }
}