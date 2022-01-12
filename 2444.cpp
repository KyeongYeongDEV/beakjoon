#include<iostream>
using namespace std;

int main(){
    int num;
    cin >> num;

    for(int i = 1; i <= num; i++){
        for(int j = num-1; j >= i; j--){
            cout<<" ";
        }
        for(int k= 1; k <= i*2-1; k++){
            cout<<"*";
        }
        cout << "\n";
    }

    for(int i =1; i <= num-1; i++) {
        for(int j = 1; j <=i; j ++){
            cout << " ";
        }
        for(int k =((num-1)*2)-((i*2)-1); k >=1; k--){
            cout << "*";
        }
        cout<<"\n";
    }
}