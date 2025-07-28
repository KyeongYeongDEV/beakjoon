#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<math.h>
using namespace std;

struct cmp{
	bool operator()(int a, int b){
		if(abs(a) == abs(b)) return a > b; //절대값 비교
		return abs(a) > abs(b);
	}
};

int main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int size;
	cin >> size;
	priority_queue<int, vector<int>, cmp> minHeap;
	

	while(size--){
		int data;  cin >> data;

		if(data == 0){
			if(minHeap.empty()){
				cout << "0\n";
			}else{
				cout << minHeap.top() << "\n";
				minHeap.pop();
			}
		}else{
			minHeap.push(data);
		}
	}
}
