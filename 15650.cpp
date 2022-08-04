#include<iostream>
#include<stack>
#include<vector>
using namespace std;

bool visited[9]={0,};
int arr[9] = {0,};
int N,M;

void dfs(int num, int cnt){
    if(cnt == M){
        for(int i=0; i < M; i++){
            cout<<arr[i] << ' ';
        }
        cout << "\n";
        return ;
    }

    for(int i= num; i <= N; i++){
        if(!visited[i]){
            visited[i] = true;
            arr[cnt] = i;
            dfs(i+1,cnt+1);
            visited[i] = false; 
        }
    }
}

int main(){cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> N >> M;
    dfs(1,0);

    return 0;
}