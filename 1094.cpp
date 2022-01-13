#include<iostream>
using namespace std;

int main(){
    cin.tie(NULL); cout.tie(NULL);

    int arr[7]= {64,32,16,8,4,2,1}, num,cnt=0;
    cin >> num;

    for(int i=0; i <7; i++){
        if(num ==0){break;}
        if(num >= arr[i]){
            num -= arr[i];
            cnt++;
        }
    }
    cout << cnt;
}