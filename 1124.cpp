#include<iostream>
#include<vector>
using namespace std;
//1124 언더프라임
//에라토네스의 체를 이용하면 쉽다.

const int MAX = 100000 + 1;
int minFactor[MAX];
vector<int> prime; 

void eratosthenes(void){    
    minFactor[0] = minFactor[1] = -1;
    for (int i = 2; i < MAX; i++){
        minFactor[i] = i; 
    }
    for (int i = 2; i*i < MAX; i++){
        if (minFactor[i] == i){
            for (int j = i * i; j < MAX; j += i){
                if(minFactor[j] == j){
                    minFactor[j] = i;
                } 
            }          
        }
    }

    for (int i = 2; i < MAX; i++){
        if (minFactor[i] == i){
            prime.push_back(i);
        }
    }
}
 

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int A, B,result = 0;
    cin >> A >> B;

    eratosthenes();

    for(int i = A; i <= B; i++){
        int cnt = 0;
        int temp = i;

        for (int j = 0; j < prime.size(); j++){
            while (!(temp % prime[j])){
                cnt++;
                temp /= prime[j];
                if (temp == 1)break;
            }
            if (temp == 1)break;
        }
        if (minFactor[cnt] == cnt) result++;
    }

    cout << result << "\n";
}


/*시간초과
int result=0;
vector<int> arr;

void find(int num){// 제일 큰 수를 기준으로 소수를 벡터에 저장
    bool tmp = true;
    for(int i =2; i < num; i++){
        for(int j =2; j <i; j++){
            if(i %j ==0){ tmp = false;}
        }
        if(tmp == true){
            arr.push_back(i);
        }
        tmp = true;
    }
}
void test(int num){//cnt가 소수인지 검사
    for(int i =0; i < arr.size(); i++){
        if(num == arr[i]){
            result++;
            break;
        }
    }
}

void underprime(int num){
    int cnt=0;
    for(int i = 0; i <arr.size(); i++){
        while(num % arr[i] == 0){
            num /= arr[i];
            cnt++;
        }
        if(num ==0)break;
    }
    test(cnt);
}

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);

    int a,b;
    cin >> a>>b;

    find(b);

    for(int i=a; i <= b; i++){
       underprime(i);
    }
    cout <<result; 
}
*/