

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct lecture {
	int num, start, end;
};

struct cmp {
	bool operator()(lecture a, lecture b) {
		return a.end > b.end; // 작은 값 우선
	}
};

bool comp(lecture a, lecture b) {
	return a.start < b.start; // 작은 값 우선
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, ans = 0;
	cin >> n;

	vector<lecture> v(n, { 0,0,0 });
	vector<int> room(n, 0);
	priority_queue<lecture, vector<lecture>, cmp> q;

	for (int i = 0; i < n; i++)	cin >> v[i].num >> v[i].start >> v[i].end;
	sort(v.begin(), v.end(), comp);  // 일찍 시작하는 강의 오름차순

	for (int i = 0; i < n; i++) {
		if (!q.empty() && (q.top().end <= v[i].start))  {// 이전에 사용하던 강의실 그대로 
			room[v[i].num-1] = room[q.top().num - 1];
			q.pop();
		}
		else  {// 새로운 강의실 사용 
			ans++;
			room[v[i].num-1] = ans;
		}
		q.push(v[i]);
	}

	cout << ans << "\n";
	for (int i = 1; i <= n; i++) cout << room[i] << "\n";
}