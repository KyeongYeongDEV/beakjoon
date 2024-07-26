#include<iostream>
#include<vector>
using namespace std;

#define MAX 201

int main(){ cout.tie(0); cin.tie(0); ios::sync_with_stdio(0);
    int T,N;

    cin >> T;

    while(T--){
        int cnt[MAX] = {0,};
        int countScore[MAX] = {0,};
        int sum[MAX][2] = {0,};
        vector<int> v(MAX);

        cin >>N;

        for(int i = 1; i <= N; i++){
            int tmp;
            cin >> tmp; 
            
            v.push_back(tmp);
            cnt[tmp]++; //팀원수 체크
        }
        
        int score = 1; 
        for(auto e : v){
            if(cnt[e] == 6){ 
                countScore[e]++;
                if (countScore[e] == 5){ // 5번째 선수 등수
                    sum[e][1] = score;
                }else if (countScore[e] < 5){ // 1~4번쨰 선수 등수의 합
                    sum[e][0] += score;
                }
                score++;
            }
        }

        int winner = 1;
        int winnerScore = 987654321;
        for(int i =1; i <= 200; i++){
            if (cnt[i] != 6) continue;
            if (sum[i][0] < winnerScore){
                winnerScore = sum[i][0];
                winner = i;
            }else if (sum[i][0] == winnerScore){
                if (sum[i][1] < sum[winner][1]){
                    winner = i;
                }
            }
        }
        cout << winner << "\n";
    }
}