#include<iostream>
using namespace std;

int main(){
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    
    int T,cnt=1, jump=2;
    int arr[3] = {-1,0,1};

    for(int i =0; i <T; i++){
        long long x,y;
        cin >> x>> y;
        int tmp =y-1;

        while(tmp !=0){
            if(tmp >= arr[jump]){
            tmp -= arr[jump];
            cnt++;
                for(int i =0; i <=2; i++){
                    arr[i]++;
                }

            }
            else{
                jump--;
            }
            jump =2;
        }
        cout<< cnt<<"\n";
        cnt =1;
    }
        
}