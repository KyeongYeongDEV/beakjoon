#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n,k,min =10000;
    vector<int> v;
    cin>>n>>k;

    for(int i=0; i < n; i++){
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
        if(k % v[i] == 0 && k / v[i] < min){min = k / v[i]; }
    }

    sort(v.begin(),v.end());
    int cnt =0;
    for(int i=v.size()-1; i >=0; i--){
        cnt+= k / v[i];
        k = k% v[i];
    }

    if(k != 0 || min == 10000){
        cout << -1;
    }else{
        if(cnt < min){min = cnt;}
        cout << min;
    }   
}