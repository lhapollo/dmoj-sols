#include <bits/stdc++.h>
using namespace std;

int n, m;
int a, b;

vector<int> adj[200001];
vector<int> in(200001);
queue<int> q;
vector<int> vis(200001);
vector<int> ans;

void dfs(int src){
    if (vis[src] == 1) {
        cout << -1 << "\n";
        exit(0);
    }
    if (vis[src] == 2) return;
    vis[src] = 1;
    for (auto i: adj[src]){
        dfs(i);
    }
    vis[src] = 2;
}

void topSort(){
    for (int i = 1; i <= n; i++){
        if (vis[i] == 0) dfs(i);
        if (in[i] == 0) q.push(i);
    }
    int curr = -1;
    while (!q.empty()){
        curr = q.front();
        q.pop();
        ans.push_back(curr);
        for (auto i: adj[curr]){
            in[i]--;
            if (in[i] == 0) q.push(i);
        }
    }
    cout << ans.size() << "\n";
    for (auto i: ans){
        cout << i << " " << 0 << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        in[b]++;
    }
    topSort();
}