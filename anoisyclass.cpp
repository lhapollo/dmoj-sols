#include <bits/stdc++.h>
using namespace std;
vector<int> adj[10001];
vector<int> in(10001,0);
vector<bool> vis(10001,0);
int n,m;

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
    queue<int> q;
    for (int i = 1; i <= n; i++){
        if (in[i] == 0){
            vis[i] = 1;
            q.push(i);
        }
    }
    int ans = 0;
    int curr = -1;
    while (!q.empty()){
        curr = q.front();
        q.pop();
        ans++;
        for (auto i: adj[curr]){
            in[i] = max(in[i]-1,0);
            if (in[i] == 0 && !vis[i]){
                vis[i] = 1;
                q.push(i);
            }
        }
    }
    cout << (ans == n? "Y":"N") << "\n";
}