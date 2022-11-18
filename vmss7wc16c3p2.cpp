#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio();
    cin.tie(0);
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    int adj[n+1][n+1];
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            adj[i][j] = 0;
        }
    }
    for (int i = 0; i < m; i++){
        int x,y;
        cin >> x >> y;
        adj[x][y] = 1;
        adj[y][x] = 1;
    }
    //bfs
    bool visited[n+1];
    memset(visited, 0, sizeof(visited));
    queue<int> buff;
    visited[a] = true;
    buff.push(a);
    int curr;
    while (!buff.empty()){
        curr = buff.front();
        //cout << curr << endl;
        buff.pop();
        if (curr == b) break;
        for (int i = 1; i <= n; i++){
            if (adj[curr][i] == 1 && !visited[i]){
                visited[i] = true;
                buff.push(i);
            }
        }
    }
    cout << (visited[b]? "GO SHAHIR!": "NO SHAHIR!");
}