#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

string arr[26];
bool check[26][26] = {false};
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1}; 
vector<int> house_cnt;
queue<pair<int,int> >  q;

void bfs(int x,int y){
    int cnt =1;
    q.push(make_pair(x,y));
    check[x][y] = true;

    while(!q.empty()){
        int xx = q.front().first;
        int yy = q.front().second;
        q.pop();
        check[xx][yy] = true;

        for(int i=0; i< 4; i++){
            int nx = xx + dx[i];
            int ny = yy + dy[i];

            if(nx >=0 && ny >=0 && check[nx][ny] == false && arr[nx][ny] =='1'){
                q.push(make_pair(nx,ny));
                check[nx][ny] = true;
                cnt++;
            }
        }
    }
    house_cnt.push_back(cnt);
}

int main(){cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int num,cnt =0; //이 카운트는 단지를 세는 변수
    cin >>num;
    for(int i=0; i< num; i++){
        cin >> arr[i];
    }
    for(int i=0; i < num; i++){
        for(int j=0; j<num; j++){
            if(arr[i][j] == '1' && check[i][j] == false){
                bfs(i,j);
                cnt++;
            }
        }
    }

    cout<< cnt<<"\n";
    sort(house_cnt.begin(),house_cnt.end());
    for(int i=0; i < house_cnt.size(); i++){
        cout << house_cnt[i]<<"\n";
    }
}