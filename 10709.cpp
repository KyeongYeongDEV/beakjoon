#include<iostream>
using namespace std;

int main(){ cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int x=0, y=0;
    cin >> x >> y;

    char c ;
    int result[x][y] ;

    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            cin >> c;
            if(c == 'c') result[i][j] = 0;
            else result[i][j] = -1;
        }
    }

    for(int i =0; i < x; i++){
        for(int j =1; j < y; j++){
            if (result[i][j] == 0) continue;
            else if (result[i][j-1] >= 0){
                result[i][j] = result[i][j-1] + 1;
            }
        }
    }

    for(int i =0 ; i < x; i++){
        for(int j =0; j < y; j++){
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }
}