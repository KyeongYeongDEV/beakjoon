#include<iostream>
using namespace std;

int main(){
    int num=0 ,cnt = 0, v =0;
    
    cin>>num;
    int arr[num];

    for(int i =0; i < num; i++){
        cin >> arr[i];
    }
    cin >> v;
    for(int i =0; i < num; i++){
        if(arr[i] == v) cnt++;
    }

    cout << cnt;
    
}