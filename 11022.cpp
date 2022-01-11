#include<iostream>
using namespace std;

int main(){
    int T;
    cin >>T;
    int arr[T], Xarr[T],Yarr[T];

    for(int i=0; i<T; i++){//입력
        cin>>Xarr[i]>>Yarr[i];
        arr[i] = Xarr[i] + Yarr[i];
    }

    for(int i=0; i<T; i++){ // 출력
        cout<< "Case #"<<i+1<<": " << Xarr[i]<<" + "<<Yarr[i]<<" = "<<arr[i]<<"\n";
    }
    return 0;
    
}