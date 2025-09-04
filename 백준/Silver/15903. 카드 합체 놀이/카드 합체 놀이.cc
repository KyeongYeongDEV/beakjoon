#include <iostream>
#include <queue>
using namespace std;

int main() { ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m;
    long long result = 0;
    cin >> n >> m;

    priority_queue<long long, vector<long long>, greater<long long> > minHeap;

    for (int i = 0; i < n; i++) {
        long long tmp;
        cin >> tmp;
        minHeap.push(tmp);
    }

    while (m--) {
        long long x = minHeap.top();
        minHeap.pop();

        long long y = minHeap.top();
        minHeap.pop();

        long long sum = x + y;

        minHeap.push(sum);
        minHeap.push(sum);
    }

    long long heapSize = minHeap.size();
    while(heapSize--) {
        result += minHeap.top();
        minHeap.pop();
    }

    cout << result << "\n";
}