#include <bits/stdc++.h>
using namespace std;

int c, r, d;
typedef pair<int, int> pi;
vector<pi> adj[10001];
vector<int> dis(10001, INT_MAX);
vector<bool> vis(10001);

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> c >> r >> d;
    for (int i = 0; i < r; i++){
        int x, y, z;
        cin >> x >> y >> z;
        adj[x].push_back(make_pair(-z,y));
        adj[y].push_back(make_pair(-z,x));
    }
    priority_queue<pi, vector<pi>, greater<pi> > q;
    dis[1] = 0;
    q.push(make_pair(0,1));
    while (!q.empty()){
        int dist = q.top().first, u = q.top().second; q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto i: adj[u]){
            int w = i.first, v = i.second;
            if (!vis[v] && dis[v] > w){dis[v] = w; q.push(make_pair(dis[v], v));}
        }
    }
    int ans = INT_MAX;
    for (int i = 0; i < d; i++){
        int x;
        cin >> x;
        ans = min(ans, -dis[x]);
    }
    cout << ans <<"\n";
}