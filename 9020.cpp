#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int number = 10000;
    int arr[10001];
    int num=0, get_num=0;    
    cin >> num;
    
    for(int i=0; i<= number; i++){
        arr[i] = i;
    }
    for(int i=2; i <= sqrt(number); i++){ //값이 0이면 소수
        if(arr[i] == 0){
            continue;
        }
    
        for(int j = i*i; j <= number; j+= i){
            arr[j] = 0;
        }
    }

    while(num--){
        cin >> get_num;
        bool check = false;

        for(int i =get_num/2; i >=2; i--){
            if(arr[i] == 0){continue;}
            if(arr[i] + arr[get_num-i] == get_num){
                cout << arr[i] << " " << arr[get_num-i]<< "\n";
                break;
            }
        }
    }
}