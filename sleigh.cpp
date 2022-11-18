#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > adj[1000000];
vector<bool> vis(100000,0);
vector<int> dist(100000,-1);
int totdist = 0;

void dfs(int src){
    for (auto i: adj[src]){
        if (!vis[i.first] && dist[i.first] == -1){
            dist[i.first] = dist[src] + i.second;
            vis[i.first] = 1;
            dfs(i.first);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(b,c));
        adj[b].push_back(make_pair(a,c));
        totdist += 2*c;
    }
    dist[0] = 0;
    dfs(0);
    int ans = 0;
    for (int i = 0; i <= n; i++){  
        //cout << dist[i] << " ";  
        ans = max(ans, dist[i]);
    }
    //cout << "\n";
    //cout << totdist << "\n";
    // cout << ans << "\n";
    //cout << totdist << "\n";
    cout << totdist - ans << "\n";
}