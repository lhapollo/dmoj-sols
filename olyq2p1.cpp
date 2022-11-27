#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> pos, diff;
int N, M;

bool valid(ll x){
    int count = 1; 
    ll sum = 0;
    for (int i = 0; i < diff.size(); i++){
        sum += diff[i];
        if (sum >= x){
            count++;
            sum = 0;
        }
    }
    return (count >= M);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++){
        int p;
        cin >> p;
        pos.push_back(p);
    }
    sort(pos.begin(), pos.end());
    ll lo = LONG_LONG_MAX, hi = 0;
    for (int i = 1; i < pos.size(); i++){
        diff.push_back(pos[i]-pos[i-1]);
        hi += diff[i-1];
        lo = min(lo,diff[i-1]);
    }
    ll ans = 0;
    while (lo <= hi){
        ll mid = (lo+hi)/2;
        if (valid(mid)){
            ans = mid;
            lo = mid+1;
        } else {
            hi = mid-1;
        }
    }
    cout << ans << endl;
}