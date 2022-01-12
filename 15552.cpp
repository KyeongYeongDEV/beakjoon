#include<iostream>
using namespace std;



int main(){   
    int num1,x,y;
    cin>>num1;
    int tmp[num1];

    for(int i=0; i<num1; i++){
        cin>>x>>y;
        tmp[i] = x+y;
    }

    for(int i=0; i<num1; i++){
        cout<< tmp[i]<<"\n";
    }

    return 0;
}