#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 1001


int main() { ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
   int n, m; // 상자 수, 아이들 수
   cin >> n >> m;

   priority_queue<int> box;
   

   for (int i = 0; i < n; i++) {
      int tmp;
      cin >> tmp;
      box.push(tmp);
   }

   for (int i = 0; i < m; i++) {
      int child =0;
      cin >> child;

      int boxValue = box.top(); box.pop();
      if (boxValue >= child) {
         box.push(boxValue - child);
      }
      else {
         cout << 0;
         return 0;
      }
   }

   cout << 1 ;


}