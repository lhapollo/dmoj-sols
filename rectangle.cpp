#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

typedef long long ll;

unordered_map<string, int> freq;

int x[1001], y[1001];
int N;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++){
        cin >> x[i] >> y[i];
        for (int j = 1; j < i; j++){
            int mx = x[i] + x[j], my = y[i] + y[j];
            ll dis = 1LL*(x[i]-x[j])*(x[i]-x[j]) + 1LL*(y[i]-y[j])*(y[i]-y[j]);
            string s = to_string(mx) + " " + to_string(my) + " " + to_string(dis);
            freq[s]++;
        }
    }
    ll ans = 0;
    for (auto i: freq){
        ans += 1LL*i.second*(i.second-1)/2;
    }
    cout << ans << "\n";
}