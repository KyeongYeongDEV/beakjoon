#include<iostream>
using namespace std;

int main(){
    int T,x=0,y=0;
    cin >>T;
    int arr[T];

    for(int i=0; i<T; i++){//입력
        cin>>x>>y;
        arr[i] = x+y;
    }

    for(int i=0; i<T; i++){ // 출력
        cout<< "Case #"<<i+1<<": " <<arr[i]<<"\n";
    }
    return 0;
    
}