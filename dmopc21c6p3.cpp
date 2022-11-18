#include <bits/stdc++.h>
using namespace std;
int adj[1501][1501];
int dis[1501][1501];
vector<pair<int, pair<int, int> > > v;
queue<pair<int, int> > q;

bool valid (int x, int y, int w, int h){
    return (x >= 1 && x <= w && y >= 1 && y <= h);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dis, 0, sizeof(dis));
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> adj[i][j];
            if (adj[i][j] != 0) {
                pair<int, int> curr = make_pair(i,j);
                v.push_back(make_pair(adj[i][j], curr));
            }
        }
    }
    sort(v.begin(), v.end());
    for (auto i: v){
        q.push(i.second);
    }
    int dir[4][2] = {{-1, 0}, {1,0}, {0, -1}, {0,1}};
    pair<int, int> curr;
    while (!q.empty()){
        curr = q.front();
        q.pop();
        int r = curr.first, c = curr.second;
        if (dis[r][c] == k) continue;
        for (int i = 0; i < 4; i++){
            int x = r + dir[i][0], y = c + dir[i][1];
            if (adj[x][y] == 0 && valid (x, y, n, m)){
                adj[x][y] = adj[r][c];
                q.push(make_pair(x,y));
                dis[x][y] = dis[r][c]+1;
            }
        }
    }   
    for (int i = 1; i<= n; i++){
        for (int j = 1; j <= m; j++){
            cout << adj[i][j] << " ";
        }
        cout << "\n";
    } 
}