#include<iostream>
using namespace std;

// 전위순회 
// 루트 왼 오
// 후위순회
// 왼 오 루트

int n=0, x =0;
int arr[10001];

void solve(int start, int end){
    int root = arr[start];
    int index = start +1 ; 
    
    if(start == end){ //  값이 하나
        cout << root << "\n";
        return ;
    }
    
    if(start > end) return ; // 다 돎
    
    while(1){
        if(index > end || arr[index] > root)  
        // 루트를 기준으로 루트보다 작은 게 
        // 루트 왼쪽 트리에 있고
        // 크다면 오른쪽 트리에 있다
        // 전위 순회 결과에서 어디까지가 서브 트리인지 찾아준다
            break;
        index++;
    }
    
    solve(start+1, index -1); // 왼쪽
    solve(index, end); // 오른쪽
    cout << root<< "\n" ;
    
}

int main(){ios::sync_with_stdio(0);cin.tie(0);	cout.tie(0);
    while(cin >> x){
        if(x == -1) break;
        
        arr[++n] = x;
    }
    solve(1, n);
    
}