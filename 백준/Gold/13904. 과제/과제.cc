#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 1001

//내림차순
bool compare(const pair<int, int> &a, const pair<int, int> &b) {
   return a.first > b.first;
}

int main() { ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
   int n;
   cin >> n;

   vector<pair<int, int> > v(n);
   int maxDay = 0;
   for (int i = 0; i < n; i++) {
      cin >> v[i].first >> v[i].second; // day, value
      if (v[i].first > maxDay) {
         maxDay = v[i].first; // 마지막 날 찾기
      }
   }

   sort(v.begin(), v.end(), compare);

   priority_queue<int> pq; // 점수 저장 최대힙

   long long totalScore = 0;
   int idx = 0;

   // 가장 늦은 마감일부터 순회
   for (int i = maxDay; i >= 1; i--) {

      // 현재 기준 과제들 pq에 추가
      while (idx < n && v[idx].first == i) {
         pq.push(v[idx].second);
         idx++;
      }

      // pq가 비어있지 않다면
      // 현재 날짜 중 할 수 있는 과제가 있다는 의미
      if (!pq.empty()) {
         totalScore += pq.top();
         pq.pop();
      }
   }
   cout << totalScore;
}