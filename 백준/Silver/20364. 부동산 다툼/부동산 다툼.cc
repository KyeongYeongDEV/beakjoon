#include <iostream>
#include <unordered_set>
#include<vector>
using namespace std;

int main() {cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    int N, Q;
    cin >> N >> Q;

    unordered_set<int> occupied; // 점유된 땅 번호 저장 // 중복x 정렬x
    vector<int> answer;

    while (Q--) {
        int want;
        cin >> want;

        int conflict = 0;
        int cur = want;

        // 현재 땅에서 루트까지 올라가며 점유된 땅 확인
        while (cur > 0) {
            if (occupied.count(cur)) {
                conflict = cur;
            }
            cur /= 2;
        }

        // 점유된 땅이 없으면 해당 땅 점유
        if (conflict == 0) {
            occupied.insert(want);
        }

        answer.push_back(conflict);
    }

    for (int res : answer) {
        cout << res << "\n";
    }

}