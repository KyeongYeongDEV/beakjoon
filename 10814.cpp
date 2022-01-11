#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    cin.tie(NULL); cout.tie(NULL);
    int num;
    vector<pair<int, string> > vec;

    for(int i =0; i < num; i++){
        int a; 
        string b;
        cin >>a>>b;
        vec.push_back(pair<int,string> (a,b));
    }

    stable_sort(vec.begin(),vec.end());

    for(int i =0; i < num; i++){
        cout<< vec[i].first<< " "<< vec[i].second<<"\n";
    }

}

/*
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class compare{
    public:
        compare(){}

    
    int age;
    string name;
    int score;
};

int main(){
    int num;
    cin >> num;
    class compare *cmp = (compare*)malloc(sizeof(compare) *num);

    for(int i =0; i < num; i++){ //입력
        cin >> cmp[i].age >>cmp[i].name;
        cmp[i].score =i;
    }

    sort(cmp,cmp+num);

    for(int i=0; i < num; i++){
        cout << cmp[i].age << " " << cmp[i].name <<"\n";
    }

}
*/