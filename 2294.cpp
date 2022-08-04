#include<iostream>
using namespace std;

int min(int a, int b){
    return a < b ? a:b;
}

int main(){cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int N,K;
    int coin[101];
    int DP[10001]={0,};

    cin >> N >> K;

    for(int i =1; i <= K; i++){
       DP[i] = 10001;
    }
   
   for(int i =1; i <= N; i++){
       cin >> coin[i];

       for(int j=coin[i]; j<=K; j++){
           DP[j] = min(DP[j],DP[j - coin[i]]+1);
       }
   }

   if(DP[K] == 10001){cout<< -1;}
   else{cout<<DP[K];}
}