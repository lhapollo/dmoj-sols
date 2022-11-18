#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
int t;

int main(){
    ios_base::sync_with_stdio(true);
    cin.tie(0);
    for (cin >> t; t >0; t--){
        int r, c;
        cin >> r >> c;
        char adj[r+1][c+1];
        bool bfs[r+1][c+1];
        int dist[r+1][c+1];
        memset(adj, '*', sizeof(adj));
        for (int i = 1; i <= r; i++){
            for (int j = 1; j <= c; j++){
                cin >> adj[i][j];
            }
        }
        pair<int, int> start = make_pair(1, 1), end = make_pair(r, c);
        pair<int, int> curr;
        memset(bfs, 0, sizeof(bfs));
        memset(dist, INF, sizeof(dist));
        queue<pair<int, int> > buff;
        buff.push(start);
        bfs[1][1] = 1;
        dist[1][1] = 1;
        while (!buff.empty()){
            curr = buff.front();
            buff.pop();
            int a = curr.first, b = curr.second;
            //cout << a << " " << b << endl;
            if (adj[a][b] == '+'){
                if (!bfs[a-1][b] && adj[a-1][b] != '*' && dist[a-1][b] == INF){
                    bfs[a-1][b] = 1;
                    dist[a-1][b] = dist[a][b]+1;
                    buff.push(make_pair(a-1,b));
                }
                if (!bfs[a+1][b] && adj[a+1][b] != '*' && dist[a+1][b] == INF){
                    bfs[a+1][b] = 1;
                    dist[a+1][b] = dist[a][b]+1;
                    buff.push(make_pair(a+1,b));
                }
                if (!bfs[a][b+1] && adj[a][b+1] != '*' && dist[a][b+1] == INF){
                    bfs[a][b+1] = 1;
                    dist[a][b+1] = dist[a][b]+1;
                    buff.push(make_pair(a,b+1));
                }
                if (!bfs[a][b-1] && adj[a][b-1] != '*' && dist[a][b-1] == INF){
                    bfs[a][b-1] = 1;
                    dist[a][b-1] = dist[a][b]+1;
                    buff.push(make_pair(a,b-1));
                }
            } else if (adj[a][b] == '|'){
                if (!bfs[a-1][b] && adj[a-1][b] != '*' && dist[a-1][b] == INF){
                    bfs[a-1][b] = 1;
                    dist[a-1][b] = dist[a][b]+1;
                    buff.push(make_pair(a-1,b));
                }
                if (!bfs[a+1][b] && adj[a+1][b] != '*' && dist[a+1][b] == INF){
                    bfs[a+1][b] = 1;
                    dist[a+1][b] = dist[a][b]+1;
                    buff.push(make_pair(a+1,b));
                }
            } else if (adj[a][b] == '-'){
                if (!bfs[a][b+1] && adj[a][b+1] != '*' && dist[a][b+1] == INF){
                    bfs[a][b+1] = 1;
                    dist[a][b+1] = dist[a][b]+1;
                    buff.push(make_pair(a,b+1));
                }
                if (!bfs[a][b-1] && adj[a][b-1] != '*' && dist[a][b-1] == INF){
                    bfs[a][b-1] = 1;
                    dist[a][b-1] = dist[a][b]+1;
                    buff.push(make_pair(a,b-1));
                }
            }
        }
        cout << (dist[end.first][end.second] == INF? -1: dist[end.first][end.second]) << endl;
    }
}