#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    //처음에 위의 코드를 빼고 제출했는데 시간 초과로 인헤 틀렸었다.
    //이 코드만 넣어줬는데 시간초과 문제가 해결됐다.

    int A=0,B=0,num =0;
    vector<int> arr;
    cin >> A>>B;

    for(int i = 0; i <A+B; i++){//입력
      cin >>num;
      arr.push_back(num);  
    }
    sort(arr.begin(), arr.end());//정렬

    for(int i =0; i < A+B; i++){//출력
        cout << arr[i] <<" ";
    }    
}