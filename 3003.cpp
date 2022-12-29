#include<iostream>
using namespace std;

int main(){ cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int arr1[6] = {1,1,2,2,2,8};
    int arr2[6] = {0};

    for(int i=0; i <6; i++){
        cin >> arr2[i];
        cout<< arr1[i] - arr2[i] << " ";
    }
}