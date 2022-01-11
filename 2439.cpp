#include<iostream>
using namespace std;

int main(){
    int num1;
    cin>>num1;

    for(int i=0; i<num1; i++){
        for(int j=num1-1; j>i;j--){
            cout<<" ";
        }
        for(int q = 0; q<=i; q++){
            cout<<"*";
        }
        cout<<"\n";
    }

    return 0;
}