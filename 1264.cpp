#include<iostream>
#include<string>
using namespace std;


int main(){cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int cnt =0;

    while(1){
        char ch;
        ch =getchar();

        if(ch == '#'){break;}

        if(ch == '\n'){    
            cout << cnt << "\n";
            cnt =0;
        }
        
        if(ch== 'a'||ch == 'A'|| ch == 'e'|| ch == 'E'|| ch == 'i'||
           ch == 'I'|| ch == 'o'|| ch == 'O'|| ch == 'u'||ch == 'U'){
            cnt++;
        }
    }
}