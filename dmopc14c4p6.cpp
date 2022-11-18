#include <bits/stdc++.h>
using namespace std;
vector<int> adj[500001];
vector<int> dis1(500001,-1), dis2(500001,-1);
queue<int> q;
int far;
int n;

void bfs(int src, vector<int>& dis){
    vector<bool> vis(500001,0);
    vis[src] = 1;
    dis[src] = 0;
    q.push(src);
    int curr = -1;
    while(!q.empty()){
        curr = q.front();
        far = curr;
        // cout << curr << endl;
        q.pop();
        for (auto i: adj[curr]){
            if (!vis[i]){
                dis[i] = dis[curr] + 1;
                vis[i] = 1;
                q.push(i);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bfs(1, dis1);
    bfs(far, dis1);
    bfs(far, dis2);
    for (int i = 1; i <= n; i++){
        cout << max(dis1[i], dis2[i])+1 << "\n";
    }
}