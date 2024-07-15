#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

int main(){cout.tie(0); cin.tie(0); ios::sync_with_stdio(0);
    int n =0, max =-987654321, start =0, end =0;
    bool check = false;
    map<int ,int> sum; //<시간, 마리수>

    cin >> n;

    for(int i =0; i < n; i++){
        int a, b;
        cin >> a >> b;

        sum[a] +=1;
        sum[b] -= 1;
    }

    int cnt =0;
    for(const auto& i : sum){
        cnt += i.second;

        if( cnt > max){//  처음 max마리가 갱신이 됐을 때가 최대 마리수
            max = cnt;
            start = i.first;
            check = true;
        }else if(cnt < max && cnt - i.second == max && check){ 
            //값이 최대 매리수에서 처음으로 줄었을 때, 누적합을 하기 전의 수, 시작 시간을 체크했는지
            end = i.first;
            check = false;
        }
    }

    cout << max << "\n" << start << " " << end;
}