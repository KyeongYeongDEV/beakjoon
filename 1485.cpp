#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int aaa(pair<int,int> a, pair<int,int> b){//길이를 게산해주는 함수
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second-b.second);
}

int main(){cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int num;
    cin >>num;
    
    while(num--){
        vector<pair<int,int> >vec;
        int x,y; 

        for(int i =0 ; i < 4; i++){
            cin >> x>>y;
            vec.push_back(make_pair(x,y));
        }

        sort(vec.begin(),vec.end());

        int a = aaa(vec[0],vec[1]);
        int b = aaa(vec[0],vec[2]);
        int c = aaa(vec[3],vec[1]);
        int d = aaa(vec[3],vec[2]);
        int e = aaa(vec[0],vec[3]);
        int f = aaa(vec[1],vec[2]);

        if(a==b && c ==d && e ==f){cout<< 1<<"\n";}
        else{cout<<0<<"\n";}
    }
}