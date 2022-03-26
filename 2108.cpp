#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
//https://www.acmicpc.net/problem/2108

int main(){cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    vector<int> vec;
    int arr[8001]={0,};
    int num,tmp=0,max=0,sum=0;

    cin >> num;

    int a;
    for(int i =0; i <num; i++){//입력
        cin >> a;
        arr[a+4000]++;//입력 받은 수번째 배열을 +1 해주어 개수를 늘려준다.
        vec.push_back(a);//입력 받은 값을 벡터에 넣는다
        sum +=a; //평균값을 구하기 위해 수의 합을 구해준다
    }

    for(int i =0; i < 8001;i++){ 
        if(arr[i] != 0){ //배열의 값이 0이라면 입력 받은 수가 없다는 뜻이므로 0이 아닐 때
            if(max < arr[i]){//최대 개수를 비교하여
                tmp = i; //숫자를 저장
                max = arr[i]; //최대개수를 저장
            }
        }
    }

    for(int i = tmp+1; i<8001; i++){ //위에서 젤 큰 걸 받을 떄 값이 max보다 클 때만 max를 초기화 시키므로 
        if(arr[i] == max){//현재 max는 수가 가장 작은 것이 들어가있다 
            tmp = i;//그렇기 때문에 다음 만나는 수가 두번째로 작은 값이 된다
            break;
        }
    }

    sort(vec.begin(),vec.end()); // 중앙값과 범위를 쉽게 찾기위해 정렬 정렬 오름차순
    sum = round(sum/(double)num); //반올림해주는 함수

    cout << sum<< "\n" 
    << vec[(num-1)/2] << "\n" 
    << tmp-4000 << "\n"
    << vec[num-1]-vec[0] << "\n"; 
}