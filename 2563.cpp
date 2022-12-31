#include<iostream>
using namespace std;

int main(){
    cin.tie(0); cout.tie(0);ios::sync_with_stdio(0);
    int n =0, x=0, y=0;
    cin >> n;
    int arr[100][100] = {0};
    int result =0;
    while(n--){
        cin >> x >> y;

        for(int i = x; i < x+10; i++){
            for(int j = y; j < y+10; j++){
                if(!arr[i][j]){
                    arr[i][j] = 1;
                    result++;
                }
            }
        } 
    }
    cout << result;
}