#include <bits/stdc++.h>
using namespace std;
vector<int> adj[10000];
int vis[10000], dist[10000];

int n;
bool cycle = false;
int ans = 0;

void dfs(int src){
    if (ans > 0) return;
    vis[src] = 1;
    for (auto x: adj[src]){
        if (vis[x] == 1){
            ans = dist[x] - dist[src] - 1;
            cycle = true;
            return;
        } else if (vis[x] == 0){
            dist[x] = dist[src]+1;
            dfs(x);
        }
    }
    vis[src] = 2;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    int x = -1, y = -1;
    while (true){
        memset(vis, 0, sizeof(vis));
        memset(dist, -1, sizeof(dist));
        cycle = false;
        cin >> x >> y;
        if (x == 0 && y == 0) break;
        dfs(x);
        if (vis[y] != 0) cout <<"Yes " << dist[y] << "\n";
        else cout << "No" << "\n";
    }
}