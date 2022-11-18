#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
vector<pi> adj[500001];
vector<int> dis1(500001), dis2(500001);
queue<int> q;
int N;
int curr, far, distfar = 0;

void bfs(int src, vector<int>& dis){
    vector<bool> vis(500001,0);
    vis[src] = 1;
    dis[src] = 0;
    q.push(src);
    while(!q.empty()){
        curr = q.front();
        // cout << curr << endl;
        q.pop();
        if (dis[curr] > distfar) {far = curr; distfar = dis[curr];}
        for (auto i: adj[curr]){
            if (!vis[i.first]){
                dis[i.first] = dis[curr] + i.second;
                vis[i.first] = 1;
                q.push(i.first);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N-1; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(b,c));
        adj[b].push_back(make_pair(a,c));
    }
    bfs(1, dis1);
    bfs(far, dis1);
    //cout << far << endl;
    bfs(far, dis2);
    //cout << far << endl;
    int radius = INT_MAX;
    for (int i = 1; i <= N; i++){
        radius = min(radius,max(dis1[i],dis2[i]));
    }
    cout << distfar << "\n" << radius << "\n";
}
