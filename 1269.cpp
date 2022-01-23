#include<iostream>
#include<map>
using namespace std;


int main(){//찾아보니 map을 이용한 좋은 방법이 있었다
    cin.tie(0);cout.tie(0); ios::sync_with_stdio(0);

    int A,B,num;
    map<int,bool> map;
    cin>>A>>B;
   
   for(int i=0; i <A+B; i++){
       cin>>num;
       if(map[num]==true){map.erase(num);}//이미 있다면 map에서 제거
       else{map[num] = true;}//없다면 map에 추가
   }
   cout << map.size();
}

/* //시간초과 
int main(){cin.tie(0);cout.tie(0); ios::sync_with_stdio(0);
    long long a,b;
    int T=0;
    cin >>a>>b;
    int sum=a+b;

    vector<int> A,B;
    for(int i=0; i<a; i++){//A집합 입력
        int tmp;
        cin >>tmp;
        A.push_back(tmp);
    }

    for(int i=0; i<b; i++){//B집합 입력
        int tmp;
        cin >>tmp;
        B.push_back(tmp);
    }
    
    for(int i=0; i <a; i++){
        for(int k=0; k <b; k++){
            if(A[i] == B[k]){sum--;break;
            }
        }
    }
    for(int i=0; i <b; i++){
        for(int k=0; k <a; k++){
            if(B[i] == A[k]){sum--;break;}
        }
    }
    cout << sum;
}
*/