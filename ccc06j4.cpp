#include <bits/stdc++.h>
using namespace std;
vector<int> adj[8];
vector<int> in(8,0);
vector<int> out;
int x = -1, y = -1;

void topsort(){
    vector<bool> vis(8,0);
    queue<int> q;
    for (int i = 1; i <= 7; i++){
        if (in[i] == 0){q.push(i); vis[i] = 1; break;}
    }
    int curr = -1;
    while(!q.empty()){
        curr = q.front();
        q.pop();
        //cout << curr << "\n";
        out.push_back(curr);
        if (out.size() == 7) break;
        for (auto i: adj[curr]){
            in[i]--;
            in[i] = max(in[i], 0);
        }
        for (int i = 1; i <= 7; i++){
            if (in[i] == 0 && !vis[i]) {q.push(i); vis[i] = 1; break;}
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    adj[1].push_back(7);
    adj[1].push_back(4);
    adj[2].push_back(1);
    adj[3].push_back(4);
    adj[3].push_back(5);
    in[1] = 1;
    in[2] = 0;
    in[3] = 0;
    in[4] = 2;
    in[5] = 1;
    in[6] = 0;
    in[7] = 1;
    while (x != 0 && y != 0){
        cin >> x >> y;
        adj[x].push_back(y);
        in[y]++;
    }
    topsort();
    if (out.size() != 7) cout << "Cannot complete these tasks. Going to bed." << "\n";
    else {
        for (int i = 0; i < out.size(); i++) cout << out[i] << (i == out.size()-1? "\n":" ");
    }
}