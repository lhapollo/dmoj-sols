#include <bits/stdc++.h>
#include <unordered_set> 
using namespace std;
int adj[501][501];
int vis[501][501];
typedef pair<int, int> pi;
#define ll long long
int N;
ll K;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(vis,-1,sizeof(vis));
    cin >> N >> K;
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            cin >> adj[i][j];
        }
    }
    ll cycle = 1;
    int a = 1, b = 2;
    int sa = 1, sb = 2;
    int ea = a;
    while (true) {
        //cout << cycle << endl;
        //cout << a << " -> " << b << endl;
        int temp = adj[b][a];
        if (vis[b][a] != -1) {
            //cout << "cycle starts " << vis[b][a] << " shows in."<<endl;
            //cycle doesn't affect answer.
            if (K < vis[b][a]) break;
            sa = a; sb = b;
            cycle -= vis[b][a];
            if (K >= vis[b][a]) K -= 1LL*(vis[b][a]-1);
            break;
        }
        vis[b][a] = cycle;
        cycle++;
        a = b;
        b = temp;
        ea = a;
    }
    // cout << sa << " " << sb << "\n";
    // cout << "cycle len: " << cycle << endl;
    //cout << K << endl;
    K %= cycle;
    if (K == 0) K += cycle;
    //cout << K << "\n";
    a = sa; b = sb;
    int ans = ea;
    for (int i = 0; i < K; i++){
        //cout << a << " -> " << b << endl;
        int temp = adj[b][a];
        ans = a;
        a = b;
        b = temp;
    }
    cout << ans << "\n";
}