#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> have_num;

bool bsreach(int key){
    int front =0, rear = have_num.size()-1;
    int mid = (front+rear)/2;
    
    while(rear>= front){
        if(have_num[mid] == key){return true;}
    
        else if(have_num[mid] < key){
            front = mid+1;
            mid = (front+rear)/2;
        }
        else{
            rear = mid-1;
            mid = (front+rear)/2;
        }       
    }
    return false;
}

int main(){cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int num,tmp;
    vector<int> cmp_num; 
    cin >> num;
    for(int i=0;i<num; i++){
        cin>>tmp;
        have_num.push_back(tmp);
    }

    cin >>num;
    for(int i=0; i<num; i++){
        cin >> tmp;
        cmp_num.push_back(tmp);
    }

    sort(have_num.begin(),have_num.end());

    
    for(int i =0; i< cmp_num.size(); i++){
        if(bsreach(cmp_num[i])){
            cout << 1 << " ";
        }
        else{
            cout<< 0 << " ";
        }
    }
}