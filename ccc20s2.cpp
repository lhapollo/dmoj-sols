#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
typedef vector<pair<int, int> > vpii;

bool valid(int x, int y, int m, int n){
    return (x >=1 && x <= m && y >=1 && y <=n);
}

vector<vpii> v(1e6 + 5);

int main(){
    ios_base::sync_with_stdio();
    cin.tie(0);
    int m, n;
    cin >> m >> n;
    bool bfs[m+1][n+1];
    memset(bfs, 0, sizeof(bfs));
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            int x; cin >> x;
            v[x].push_back(make_pair(i,j));
        }
    }
    queue<pair<int, int> > buff;
    bfs[m][n] = 1;
    buff.push(make_pair(m, n));
    pair<int, int> curr;
    while (!buff.empty()){
        curr = buff.front();
        buff.pop();
        for (auto i: v[curr.first * curr.second]){
            if (i.first == 1  && i.second == 1){
                bfs[i.first][i.second] =1;
                cout << "yes\n";
                return 0;
            } 
            if (!bfs[i.first][i.second]){
                bfs[i.first][i.second] = 1;
                buff.push(i);
            }
        }
    }
    cout << "no\n";
    return 0;
}