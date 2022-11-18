#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1000000];
vector<bool> pho(1000000);
vector<bool> vis(1000000, 0);
vector<int> dis(1000000);
int n, m;
int far, totdist = 0;
bool x = 0;

void dfs(int src, int prev){
    for (auto i: adj[src]){
        if (i != prev){
            dfs(i, src);
            if (pho[i]) pho[src] = 1;
        }
    }
}

void bfs(int src){
    totdist = 0;
    queue<int> q;
    int curr;
    vector<bool> vis(1000000, 0);
    dis[src] = 0;
    vis[src] = 1;
    q.push(src);
    while (!q.empty()){
        curr = q.front(); far = curr;
        q.pop();
        for (auto i: adj[curr]){
            if (pho[i] && !vis[i]){
                vis[i] = 1;
                dis[i] = dis[curr] + 1;
                totdist += 2;
                q.push(i);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    int num;
    for (int i = 0; i < m; i++){
        cin >> num;
        pho[num] = 1;
    }
    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(num, -1);
    //for (int i = 0; i < n; i++) cout << pho[i] << " ";
    bfs(num);
    bfs(far);
    //cout << far << endl;
    //cout << totdist << "\n";
    int diameter = 0;
    for (int i = 0; i < n; i++) {
        if (pho[i]) diameter = max(diameter, dis[i]);
    }
    cout << totdist - diameter << "\n";
}