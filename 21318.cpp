#include <iostream>
#include<vector>
using namespace std;

#define MAX 100001

int main() {cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int n =0,q =0, cnt[MAX] = {0,};
    vector<int> v;
    cin >> n;

    for(int i=0; i < n; i++){
        int tmp = 0; 
        cin >> tmp;

        v.push_back(tmp);
        
        if( i == 0) continue;
        else if(v[i-1] > tmp){
            cnt[i] = cnt[i - 1] + 1;
        }else{
            cnt[i] = cnt[i-1];
        }    
    }

    cin >> q;

    while(q--){
        int x =0, y =0; 
        cin >> x >> y;

        cout << cnt[y-1] - cnt[x -1] << "\n";
    }
}