#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> ans(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    for (int i = 0; i < n; i++) {
        // 스택이 비어있지 않고
        // 스택 top이 현재 v[i]보다 작으면
        // 현재 v[i]가 스택 top의 오큰수이다
        while (!st.empty() && v[st.top()] < v[i]) {
            ans[st.top()] = v[i];
            st.pop();
        }
        st.push(i);
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
}
