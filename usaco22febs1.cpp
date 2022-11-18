#include <bits/stdc++.h>
using namespace std;
bitset<501> vis[501]; //whether there is a path from i to j -> vis[i][j]
vector<int> adj[501];
int N, X;

void dfs(int i, int j){
    if (vis[i][j]) return;
    vis[i][j] = 1;
    for (int t: adj[j]){
        dfs(i, t);
    }
}

int main(){
    cin >> N;
    for (int i = 1; i <= N; i++){
        bool flag = false;
        for (int j = 1; j <= N; j++){
            cin >> X;
            if (!flag) adj[i].push_back(X);
            if (X == i) flag = true;
        }
    }
    for (int i = 1; i <= N; i++){
        dfs(i, i);
    }
    for (int i = 1; i <= N; i++){
        for (int g: adj[i]){
            if (vis[g][i]) {cout << g << "\n"; break;}
        }
    }
}