#include <bits/stdc++.h>
using namespace std;
vector<int> adj[200001];
vector<int> in(200001,0);
vector<bool> vis(200001,0);
int n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++){
        int c;
        cin >> c;
        in[i] = c;
        for (int j = 0; j < c; j++){
            int x;
            cin >> x;
            adj[x].push_back(i);
        }
    }
    queue<int> q;
    vector<int> out;
    for (int i = 1; i <= n; i++){
        if (in[i] == 0) {q.push(i); vis[i] = 1;}
    }
    int curr;
    while (!q.empty()){
        curr = q.front();
        out.push_back(curr);
        q.pop();
        for (auto i: adj[curr]){
            in[i] = max(0,in[i]-1);
            if (in[i] == 0 && !vis[i]) {vis[i] = 1; q.push(i);}
        }
    }
    for (auto i: out) cout << i << " ";
}