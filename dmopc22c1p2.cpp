#include <bits/stdc++.h>
using namespace std;
int N,M;
vector<int> adj[1000001]; 
vector<pair<int, int> > dis1[1000001], dis2[1000001]; 
int a[1000001];
int color = -1;

void bfs(int src, vector<pair<int, int> > dis[]){
    queue<int> buff; 
    bool vis[1000001];
    int dist[1000001];
    memset(vis, 0, sizeof(vis));
    memset(dist, -1, sizeof(dist));
    dist[src] = 0;
    vis[src] = 1;
    buff.push(src);
    int curr = -1;
    while (!buff.empty()){
        curr = buff.front();
        buff.pop();
        color = a[curr];
        if (dis[color].size() < 2) {
            dis[color].push_back(make_pair(curr, dist[curr]));
        }
        for (auto i: adj[curr]){
            if (!vis[i] && dist[i] == -1){
                buff.push(i);
                vis[i] = 1;
                dist[i] = dist[curr]+1;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; i++){
        cin >> a[i];
    }
    for (int i = 0; i < M; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    bfs(1, dis1);
    bfs(N, dis2);
    int ans = INT_MAX;
    for (int i = 1; i <= N; i++){
        for (auto j: dis1[i]){
            for (auto k: dis2[i]){
                if (j.first != k.first) ans = min(ans, j.second + k.second);
            }
        }
    }
    cout << (ans == INT_MAX? -1: ans) << "\n";
}