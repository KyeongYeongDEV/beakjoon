#include<iostream>
#include<queue>
#include<vector>
using namespace std;

#define MAX 401
#define INF 987654321

int main(){
    int v,e,result = INF;
    int arr[MAX][MAX];

    cin >>  v >>e;

    for(int i=0; i < MAX; i++){ //초기화
        for(int j=0; j < MAX; j++){
            arr[i][j] = INF;
        }
    }

    for(int i =0; i < e; i++){ //입력
        int x,y,z;
        cin >>x>>y>>z;

        arr[x][y] = z;
    }
    
    for(int i=1; i <=v; i++){ //플로이드 와샬
        for(int j =1; j <= v; j++){
            for(int k=1; k <= v; k++){
                if(arr[i][j] > arr[i][k] + arr[k][j]){
                    arr[i][j] = arr[i][k] + arr[k][j];
                }
            }
        }
    }

    for(int i = 1; i <=v; i++){
        result = min(result, arr[i][i]);
    }

    cout << (result == INF ? -1: result);
}