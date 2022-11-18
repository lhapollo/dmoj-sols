#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

bool valid(int x, int y, int n, int m){
    return (x >= 1 && x <= n && y >= 1 && y <= m);
}

int main(){
    ios_base::sync_with_stdio();
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    bool adj[n+1][m+1];
    bool bfs[n+1][m+1];
    int dist[n+1][m+1];
    memset(dist, INF, sizeof(dist)); 
    memset(bfs, 0, sizeof(bfs));
    pair<int, int> start, end, curr;
    for (int i = 1; i <= n; i++){
        for (int j =1; j <= m; j++){
            char c; cin >> c;
            if (c == 's') {
                start = make_pair(i,j);
                adj[i][j] = 1;
            }
            else if (c == 'e'){
                end = make_pair(i,j);
                adj[i][j] = 1;
            } 
            else if (c == '.'){
                adj[i][j] = 1;
            }
            else if (c == 'X') adj[i][j] = 0;
        }
    }
    bfs[start.first][start.second] = 1;
    queue<pair<int, int> > buff;
    buff.push(start);
    dist[start.first][start.second] = 0;
    while (!buff.empty()){
        curr = buff.front();
        buff.pop();
        if (curr == end) break;
        int a = curr.first, b = curr.second;
        //cout << a << " " << b << endl;
        if (valid(a-1, b, n, m) && !bfs[a-1][b] && dist[a-1][b] == INF && adj[a-1][b]){
            dist[a-1][b] = dist[a][b]+1;
            bfs[a-1][b] = 1;
            //cout << a-1 << " " << b << endl;
            buff.push(make_pair(a-1,b));
        }
        if (valid(a+1, b, n, m) && !bfs[a+1][b] && dist[a+1][b] == INF && adj[a+1][b]){
            dist[a+1][b] = dist[a][b]+1;
            bfs[a+1][b] = 1;
            //cout << a+1 << " " << b << endl;
            buff.push(make_pair(a+1,b));
        }
        if (valid(a, b-1, n,m) && !bfs[a][b-1] && dist[a][b-1] == INF && adj[a][b-1]){
            dist[a][b-1] = dist[a][b]+1;
            bfs[a][b-1] = 1;
            //cout << a << " " << b-1 << endl;
            buff.push(make_pair(a,b-1));
        }
        if (valid(a, b+1, n,m) && !bfs[a][b+1] && dist[a][b+1] == INF && adj[a][b+1]){
            dist[a][b+1] = dist[a][b]+1;
            bfs[a][b+1] = 1;
            buff.push(make_pair(a,b+1));
            //cout << a << " " << b+1 << endl;
        }
        //cout << "-----------------------------\n";
    }
    cout << (dist[end.first][end.second] != INF? dist[end.first][end.second]-1: -1)<< endl;
}