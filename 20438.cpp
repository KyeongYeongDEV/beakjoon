#include<iostream>
using namespace std;
#define MAX 5004


int main(){ cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int N, K, Q, M, a =0 , b =0 ;
    int arr[MAX] = {0,};
    int sum[MAX] = {0,};
    int sleep[MAX] = {0,};


    cin >> N >> K >> Q >> M;

    //졸았는 사람 표시
    for(int i =0; i < K; i++){
        cin >> a;
        sleep[a] = 1;
    }

    for(int i = 0; i < Q; i++){
        cin >> a;
        int k = 1;

        if(!sleep[a]){
            while(a * k <= N + 2){
                int tmp = a * k;
                if(!sleep[tmp]){//출석 확인
                    arr[tmp] = 1;
                }
                k++;
            }
        }
    }

    //출석한 인원의 누적합
    for( int i = 3; i <= N + 2; i++){
        sum[i] = sum[i - 1] + arr[i];
    }

    //구간 별 결과 출력
    for(int i = 0; i < M; i++){
        cin >> a >> b;
        //구간 전체 인원 - 구간 출석한 인원수 = 구간 출석 못한 인원수
        cout << (b - a + 1) - (sum[b] - sum[a-1]) << "\n";
    }
}