#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n=0;
    cin >> n;
    vector<pair<pair<int,int>, int> > vec;

    int num1,num2,num3;
    for(int i=0; i < n; i++){
        cin >> num1 >> num2 >> num3;
        vec.push_back(make_pair(make_pair(num2,num1),num3));
    }

    int result=vec[n-1].second, tmp = vec[n-1].first.second;
    for(int i = n-2; i >=0; i--){
        if(tmp >= vec[i].first.first){
            result += vec[i].second;
            tmp = vec[i].first.second;
        }
    }

    cout << result;
}