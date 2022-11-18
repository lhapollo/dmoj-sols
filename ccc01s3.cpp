#include <bits/stdc++.h>
using namespace std;

bool adj[27][27];
bool vis[27];
vector<pair<int, int> > v;

void dfs(int src, int dst){
    if (vis[dst]) return;
    vis[dst] = 1;
    for (int i = 1; i <= 26; i++){
        if (adj[dst][i]) dfs(src, i);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(adj, 0, sizeof(adj));
    memset(vis, 0, sizeof(vis));
    string road = "";
    while (road != "**"){
        cin >> road;
        if (road == "**") break;
        int c1 = (int) road[0], c2 = (int) road[1];
        c1 -= 64; c2 -= 64;
        adj[c1][c2] = 1;
        adj[c2][c1] = 1;
        v.push_back(make_pair(c1, c2));
    }
    int ans = 0;
    for (auto i: v){
        int a = i.first, b = i.second;
        memset(vis, 0, sizeof(vis));
        adj[a][b] = 0;
        adj[b][a] = 0;
        dfs(1, 1);
        if (!vis[2]) {
            char c1, c2;
            c1 = a+64;
            c2 = b+64;
            cout << c1 << c2 << "\n";
            ans++;
        }
        adj[a][b] = 1;
        adj[b][a] = 1;
    }
    cout << "There are " << ans << " disconnecting roads." << "\n";
}