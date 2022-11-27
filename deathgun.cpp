#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

typedef unordered_map<string, vector<string> > ms;
typedef unordered_map<string, int> mi;
typedef unordered_map<int, string> is;
typedef unordered_map<string, bool> mb;

ms adj;
mi in;
is order;
mi order2;
mb vis;
mb check;

int m;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> m;
    int count = 1;
    for (int i = 0; i < m; i++){
        string a, b;
        cin >> a;
        if (!check[a]){
            check[a] = 1;
            order[-count] = a;
            order2[a] = -count;
            count++;
        }
        cin >> b;
        if (!check[b]){
            check[b] = 1;
            order[-count] = b;
            order2[b] = -count;
            count++;
        }
        adj[b].push_back(a);
        in[a]++;
    }
    priority_queue<int> q;
    for (auto i: order){
        if (in[i.second] == 0){
            q.push(i.first);
            vis[i.second] = 1;
        }
    }
    int curr;
    vector<string> ans;
    while (!q.empty()){
        curr = q.top();
        q.pop();
        //cout << curr << endl;
        string val = order[curr];
        ans.push_back(val);
        for (auto i: adj[val]){
            in[i] = max(0,in[i]-1);
            if (in[i] == 0 && !vis[i]){
                vis[i] = 1;
                q.push(order2[i]);
            }
        }
    }
    for (auto i: ans){
        cout << i << "\n";
    }
}