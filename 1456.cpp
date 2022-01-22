#include <iostream>
#include <vector>
using namespace std;
const long long MAX = 10000000 + 1; 

long long minFactor[MAX];
vector<long long> prime; 

void eratosthenes(void){
    minFactor[0] = minFactor[1] = -1;

    for (long long i = 2; i < MAX; i++)
            minFactor[i] = i;
 
    for (long long i = 2; i*i < MAX; i++)
        if (minFactor[i] == i)
            for (long long j = i * i; j < MAX; j += i)
                if (minFactor[j] == j)
                    minFactor[j] = i;
       
        for (int i = 2; i < MAX; i++)
            if (minFactor[i] == i)
                prime.push_back(i);
}

 

int main(void){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        long long A, B;
        cin >> A >> B;

        eratosthenes();

        long long result = 0;
        for (int i = 0; i < prime.size(); i++)
        {
            long long num = prime[i];
                 
            //num이 long long 범위 초과하지 않도록 하는 조건
            while (prime[i] <= B / num){
                         if (prime[i] * num >= A)
                                 result++;
                         num *= prime[i];
                 }
        }
        cout << result << "\n";

        return 0;

}