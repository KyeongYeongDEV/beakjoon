#include<iostream>
#include<queue>
using namespace std;
//실5 요세푸스 문제
//큐를 직접 구현하다 암만 생각해도 시간 초과가 뜰 거 같아서 stl를 이용했다

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);

    int N,K;
    queue<int> Q;
    cin >> N >> K;

    for(int i =1; i <=N; i++){ //큐에 순서 삽입
        Q.push(i);
    }
    cout <<"<";

    int i =1;

    while(N-1){// N이 0이 될 때까지 | -1 한 이유는 제일 마지막은 출력을 달리해야 하기 때문
        if(i% K != 0){//K번쨰가 아니면 큐에 다시 넣고 삭제
            Q.push(Q.front());
            Q.pop();
        }
        else{//K번째이면
            cout << Q.front()<< ", ";
            Q.pop();
            N--; //K번째의 수를 출력했기 때문에 N--
        }
        i++;
    }
    cout <<Q.front()<< ">";
}