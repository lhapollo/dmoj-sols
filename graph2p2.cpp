#include <bits/stdc++.h>
using namespace std;

int N;
bool adj[1001][1001];
int vis[1001];
bool cycle = false;

void dfs(int src){
    if (vis[src] == 2) return;
    if (vis[src] == 1){
            cycle = true;
            return;
        }
    vis[src] = 1;
    //cout << "node: " << src << endl;
    for (int i = 1; i<= N; i++){
        if (adj[src][i] == 1) dfs(i);
    }
    vis[src] = 2;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    memset(vis, 0, sizeof(vis));
    for (int i =1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            cin >> adj[i][j];   
        }
    }
    for (int i = 1; i <= N; i++){
        if (vis[i] == 0) dfs(i);
    }
    cout << (cycle? "NO":"YES") << "\n";
}