#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
vector<int> v;
vector<vector<int> > adj;

int main(){
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++){
        vector<int> g;
        adj.push_back(g);
    }
    for (int i = 1; i <= n; i++){
        int m; cin >> m;
        if (m == 0) {
            v.push_back(i);
            continue;
        }
        for (int j = 0; j < m; j++){
            int c; cin >> c;
            adj[i].push_back(c);
        }
    }
    bool visited[n+1];
    int dist[n+1];
    queue<int> buff;
    memset(visited, false, sizeof(visited));
    memset(dist, INF, sizeof(dist));
    visited[1] = true;
    buff.push(1);
    dist[1] = 1;
    int curr;
    while (!buff.empty()){
        curr = buff.front();
        buff.pop();
        //cout << curr << endl;
        for (auto i: adj[curr]){
            if (!visited[i] && dist[i] == INF){
                dist[i] = dist[curr] + 1;
                visited[i] = true;
                buff.push(i);
            }
        }
    }
    //for (auto i: dist) cout << i << endl;
    int ans = INF;
    bool connected = true;
    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            connected = false;
            break;
        }
    }
    cout << (connected? "Y":"N") <<"\n";
    for (auto i: v){
        //cout << i << endl;
        ans = min(ans, dist[i]);
    }
    cout << ans <<"\n";
}