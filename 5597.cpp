#include<iostream>
using namespace std;

int main(){
    bool check[30] = {false};

    for(int i=0; i < 28; i++){
        int tmp=0;
        cin >> tmp;
        check[tmp-1] = true;
    }

    for(int i=0; i < 30; i++){
        if(!check[i]) cout<<i+1 << "\n";
    }
}