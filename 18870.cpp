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
    //unique함수 
    // 정렬된 1234455 를 1234545로 바꿔준 후 뒤에 있는 45의 4부분의 주소를 반환한다.
    //erase를 이용해 unique로부터 얻은 주소부터 끝까지 지워주면 된다.
    for(int i=0; i< num; i++){
        //auto it = lower_bound(cpy_vec.begin(),cpy_vec.end(),vec[i]);
        //cout<< it - cpy_vec.begin()<<' ';
    }
}