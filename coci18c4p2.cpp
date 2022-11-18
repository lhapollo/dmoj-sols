#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1000001];
bool vis[1000001];
int n, m;

void bfs(){
    queue<int> buff;
    buff.push(1);
    int curr;
    while (!buff.empty()){
        curr = buff.front();
        buff.pop();
        for (auto i: adj[curr]){
            if (!vis[i]){
                vis[i] = 1;
                buff.push(i);
            }
        }
    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[b].push_back(a);
    }
    if (adj[1].size() == 0){vis[1] = 1;}
    bfs();
    for (int i = 1; i <= n; i++) cout << vis[i];
}