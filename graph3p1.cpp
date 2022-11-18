#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
vector<int> adj[30001];
bool bfs[30001];
int dist[30001];
queue<int> buff;
int n, m, a, b;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int k;
    cin >> k;
    memset(dist, INF, sizeof(dist));
    for (int i = 0; i < k; i++){
        int x;
        cin >> x;
        bfs[x] = 1;
        dist[x] = 0;
        buff.push(x);
    }
    int curr, ans = 0;
    while (!buff.empty()){
        curr = buff.front();
        buff.pop();
        for (auto i: adj[curr]){
            if (!bfs[i] && dist[i] == INF){
                dist[i] = dist[curr]+1;
                bfs[i] = 1;
                buff.push(i);
                ans = max(ans, dist[i]);
            }
        }
    }
    cout << ans << "\n";
}