#include<iostream>
using namespace std;

int main(){
    int A,B,C, tmp=0, num=0;
    int arr[10]={0,1,2,3,4,5,6,7,8,9};
    int cnt[10]={0};
    cin>>A>>B>>C;
    num= A*B*C;

    while(1){               
        tmp = num%10;
        num/=10;
        if(tmp ==0 && num ==0){break;}
        for(int i=0; i<10;i++){
            if(tmp == arr[i]){
                cnt[i]++;
            }
        }       
    }

    for(int i=0; i<10; i++){
        cout<<cnt[i]<<"\n";
    }
}