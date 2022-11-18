#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
int N;
vector<int> v[10001];
bool vis[10001];
int dist[10001];
queue<int> q;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N-1; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    memset(vis, 0, sizeof(vis));
    memset(dist, INF, sizeof(dist));
    vis[1] = 1;
    dist[1] = 0;
    int curr;
    q.push(1);
    while (!q.empty()){
        curr = q.front();
        q.pop();
        for (auto i: v[curr]){
            if (!vis[i] && dist[i] == INF){
                vis[i] = 1;
                dist[i] = dist[curr]+1;
                q.push(i);
            }
        }
    }
    int far = -1, node = -1;
    for (int i = 1; i <= N; i++){
        if (dist[i] > far) {far = dist[i]; node = i;}
    }        
    //cout << node << " " << far;
    memset(vis, 0, sizeof(vis));
    memset(dist, INF, sizeof(dist));
    vis[node] = 1;
    dist[node] = 0;
    q.push(node);
    while (!q.empty()){
        curr = q.front();
        q.pop();
        for (auto i: v[curr]){
            if (!vis[i] && dist[i] == INF){
                vis[i] = 1;
                dist[i] = dist[curr]+1;
                q.push(i);
            }
        }
    }
    for (int i = 1; i <= N; i++){
        if (dist[i] > far) {far = dist[i]; node = i;}
    }        
    cout << far << "\n";
}