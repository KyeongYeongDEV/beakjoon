#include<iostream> 
using namespace std;
 
int main(){
    int N; 
    cin >> N;
 
    for (int i = 0; i < N; i++){
        for (int k = 0; k < i; k++){
            cout << " ";
        }
        for (int j = 0; j < (N - i) * 2 - 1; j++){
            cout << "*";
        }
        cout << "\n";
    }

    for (int i = 1; i < N; i++){
        for (int k = N - 1; k > i; k--){
            cout << " ";
        }
        for (int j = 0; j < (i + 1) * 2 - 1; j++){
            cout << "*";
        }
        cout << "\n";
    }
}