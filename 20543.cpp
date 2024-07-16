#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long arr[2001][2001];
long long sum[2001][2001];
int N, M;

void input(){
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			long long tmp; 
            cin >> tmp;

			arr[i][j] = -1 * tmp;
		}
	}
}

void print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << sum[i][j] << " ";
		cout << "\n";
	}
}
void solve() {
	int r = M / 2;
	int start = r;
	int end = N - r;

	for (int i = start; i < end; i++) {
		for (int j = start; j < end; j++) {
			sum[i][j] = arr[i - r][j - r];
			if (i - r - 1 >= 0) 
				sum[i][j] -= arr[i - r - 1][j - r];
			if (j - r - 1 >= 0) 
				sum[i][j] -= arr[i - r][j - r - 1];
			if (i - r - 1 >= 0 && j - r - 1 >= 0) 
				sum[i][j] += arr[i - r - 1][j - r - 1];
			if (i - M >= 0)
				sum[i][j] += sum[i - M][j];
			if (j - M >= 0)
				sum[i][j] += sum[i][j - M];
			if (i - M >= 0 && j - M >= 0)
				sum[i][j] -= sum[i - M][j - M];
		}
	}
}

int main() {cout.tie(0);cin.tie(0);ios_base::sync_with_stdio(0);
    input();
	solve();
	print();
}