#include <bits/stdc++.h>
using namespace std;
int n;
long long k;
int arr[200001], dist[200001];
bool vis[200001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(vis, 0, sizeof(vis));
    memset(dist, -1, sizeof(dist));
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    for (int cur = 1; ; cur = arr[cur]){
        int next = arr[cur];
        if (vis[next]){
            int len = dist[cur] - dist[next] + 1;
            k %= len;
        }
        if (k == 0) {cout << cur << "\n"; break;}
        k--;
        dist[next] = dist[cur]+1;
        vis[cur] = 1;
    }
}