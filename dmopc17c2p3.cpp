#include <bits/stdc++.h>
using namespace std;    
int N, R;
vector<int> adj[200001];
queue<int> q;
bool vis[200001];
int dist[200001];
int pre[200001]; //stores path where prev[i] holds the value of the previous node. 

/*
idea: run multi-source bfs for each position of a rabbit.
then run bfs on the carrot position and store its path, and then find the smallest distance between a position and a rabbit at any given time.
*/

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> R;
    for (int i = 0; i < N-1; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(vis,0, sizeof(vis));
    memset(dist,INT_MAX, sizeof(dist));
    for (int i = 0; i < R; i++){
        int c;
        cin >> c;
        vis[c] = 1;
        q.push(c);
        dist[c] = 0;
    }
    int cur;
    while(!q.empty()){
        cur = q.front();
        q.pop();
        for (auto i: adj[cur]){
            if (!vis[i]){
                vis[i] = 1;
                dist[i] = dist[cur] + 1;
                q.push(i);
            }
        }
    }
    memset(vis,0, sizeof(vis));
    int x, y;
    cin >> x >> y;
    q.push(x);
    vis[x] = 1;
    pre[x] = -1; //starting point
    while (!q.empty()){
        cur = q.front();
        q.pop();
        for (auto i: adj[cur]){
            if (!vis[i]){
                vis[i] = 1;
                pre[i] = cur;
                q.push(i);
            }
        }
    }
    int ans = INT_MAX;
    for (int i = y; i != -1; i = pre[i]){
        ans = min(ans, dist[i]);
    }
    cout << ans << "\n";
}