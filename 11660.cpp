#include<iostream>
#include<vector>
using namespace std;
#define MAX 1030

vector<pair< pair<int,int>, pair<int,int> > > v;
int arr[MAX][MAX] = {0,};
int sum[MAX][MAX] = {0,};
int n, m;

int main(){ cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

    cin >> n >> m;

    for(int i = 1 ; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> arr[i][j];
        }
    }
    for(int i = 0; i < m; i++){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        v.push_back({{x1, y1}, {x2,y2}});
    }

    // 누적합
    for(int i =1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + arr[i][j];
        }
    }

    for(int i =0; i< m; i++){
        int x1 = v[i].first.first;
        int y1 = v[i].first.second;
        int x2 = v[i].second.first;
        int y2 = v[i].second.second;

        cout << sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1] << "\n";
    }
}