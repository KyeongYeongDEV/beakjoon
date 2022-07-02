#include<iostream>
#include<deque>
using namespace std;

int main(){cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    deque<int> D;
    int N,M,num=0,result =0;
    cin >> N>>M;

    for(int i=1; i<=N;i++){ //덱에 범위만큼 삽입
        D.push_back(i);
    }

    for(int i =0; i < M; i++){
        cin >>num;
        int left=0,right=0;

        for(int j=0; j < D.size(); j++){ //오른쪽
            if(D[j] == num){break;}
            left++;
        }

        for(int j=D.size()-1; j >=0; j--){ //왼쪽
            if(D[j] == num){break;}
            right++;
        }

        //개수가 더 작은 것을 총합에 넣어준다.
        if(left <= right){
            result += left;

            while(left--){ //회전시키기
                D.push_back(D.front());
                D.pop_front();
            }
            D.pop_front();
        }
        else{
            result++;
            result += right;

            while(right--){
                D.push_front(D.back());
                D.pop_back();
            }
            D.pop_back();
        }
    }

    cout << result;

    return 0;
}