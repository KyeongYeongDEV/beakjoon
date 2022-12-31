#include<iostream>
using namespace std;

int main(){
    int Array[10][10] = {0};
    int tmp =0, max = 0, x=1, y=1;

    for(int i =1; i<=9; i++){
        for(int j =1; j<=9; j++){
            cin >> tmp;
            Array[i][j] = tmp;

            if(Array[i][j] > max){
                max = Array[i][j];
                x = i;
                y = j;
            }
        }
    }

    cout << max << "\n" << x << " " << y;
}