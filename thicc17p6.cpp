#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
#define pb(x) push_back(x)
int N, T;
vector<pi> adj[200001];
vector<int> dis(200001), dis2(200001);
int far = 0;
int totlen = 0;

void bfs(int src, vector<int>& dst){
    queue<int> q;
    vector<bool> vis(200001);
    int currdist = -1;
    dst[src] = 0;
    vis[src] = 1;
    q.push(src);
    int curr = -1;
    while (!q.empty()){
        curr = q.front();
        q.pop();
        if (dst[curr] > currdist){far = curr; currdist = dst[curr];}
        for (auto i: adj[curr]){
            if (!vis[i.first]){
                vis[i.first] = 1;
                dst[i.first] = dst[curr] + i.second;
                q.push(i.first);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> T;
    for (int i = 0 ; i < N-1; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].pb(make_pair(b,c));
        adj[b].pb(make_pair(a,c));
        totlen += c*2;
    }
    bfs(1, dis);
    //cout << far << "\n";
    bfs(far, dis);
    //cout << far << "\n";
    bfs(far, dis2);
    //cout << totlen << "\n";
    for (int i = 1; i <= N; i++){
        if (adj[i].size() == T) {
            cout << i << " " << totlen - max(dis[i], dis2[i]) << "\n";
        }
    }
}