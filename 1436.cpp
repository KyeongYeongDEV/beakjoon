#include<iostream>
using namespace std;

int main(){cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int num, i=666,result=0,tmp;
    cin>> num;

    while(1){
        tmp = i;

        do{
            if(tmp %1000==666){
                result++;
                break;
            }
            tmp /=10;
        }while(tmp >0);

        if(result == num){
            cout << i<<"\n";
            break;
        }
        i++;
    }    
}