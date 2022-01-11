#include<iostream>
using namespace std;

int main(){
    int T;
    double tmp,Isum=0,Dsum=0;
    cin >> T;

    for(int i =0; i<T; i++){
        int a;
        cin >> a;
        double arr[a][2];
        for(int k =0; k <a; k++){
            for(int q =0; q <2; q++){
                cin >> arr[k][q];
                if(q == 0){
                    Isum += arr[k][0];
                }
                else{
                    tmp = arr[k][0] * arr[k][1];
                    Dsum += tmp;
                }
            }
        }
        Dsum /=Isum;
        cout.precision(2);
        cout << Isum<<" "<<Dsum<<"\n";
        Isum =0; Dsum =0;
    }
}