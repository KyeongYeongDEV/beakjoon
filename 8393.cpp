#include<iostream>
using namespace std;

int main(){
    int num1,sum=0;
    cin >> num1;

    for(int i =1; i<=num1; i++){
        sum+=i;
    }

    cout<<sum;

    return 0;
    
}