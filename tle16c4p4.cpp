#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#include <unordered_set>
typedef pair<int, int> pi;

int n, m, q;
vector<pi> adj[100001];
ll curr = -1;
int far = -1;

vector<pi> eps; //endpoints
vector<bool> vis(100001,0), vis2(100001,0), wow(100001,0);
vector<ll> dis(100001,-1);

ll diameter = 0;

//dfs for q1
void dfs(int src, ll x, vector<bool>& topvis){
    topvis[src] = 1;
    wow[src] = 1;
    dis[src] = x;
    if (dis[src] > curr){
        far = src;
        curr = dis[src];
    }
    for (auto i: adj[src]){
        if (!topvis[i.first]){
            dfs(i.first, x+i.second, topvis);
        }
    }
}

//dfs for q2
void dfs(int src, ll x, vector<bool>& topvis, vector<ll>& dis, unordered_set<int>& n){
    n.insert(src);
    topvis[src] = 1;
    dis[src] = x;
    if (dis[src] > curr){
        far = src;
        curr = dis[src];
    }
    for (auto i: adj[src]){
        if (!topvis[i.first]){
            dfs(i.first, x+i.second, topvis, dis, n);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> q;
    for (int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(b,c));
        adj[b].push_back(make_pair(a,c));
    }
    
    for (int i = 1; i <= n; i++){
        int a, b;
        if (!wow[i]){
            far = 0;
            curr = -1;
            dfs(i,0,vis);
            a = far;
            curr = -1;
            dfs(far,0,vis2);
            b = far;
            eps.push_back(make_pair(a,b));
            diameter += dis[far];
        }
    }
    if (q == 1) cout << diameter + eps.size()-1 << "\n";
    else if (q == 2){
        vector<ll> d2(100001,0);
        ll ans = -1;
        bool b = true;
        for (auto i: eps){
            unordered_set<int> nodes;
            vector<bool> v(100001,0);
            dfs(i.second, 0, v,d2,nodes);
            ll rad = LONG_LONG_MAX;
            for (auto i: nodes){
                ll temp = max(dis[i],d2[i]);
                if (temp < rad){
                    rad = temp;
                } 
            }
            if (rad > ans){
                b = 1;
                ans = rad;
            } else if (rad == ans){
                b = 0;
            }
        }
        if (b == 0) ans++;
        cout << ans << "\n";
    }
}