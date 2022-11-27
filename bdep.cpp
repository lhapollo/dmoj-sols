#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef unsigned long long ll;    
ll p, y, t;

bool valid(ll n, double per){
    ll sum = 0;
    for (int i = 0; i < y; i++){
        sum += n;
        sum += sum*p/100;
        if (sum >= t) return true;
    }
    //cout << sum << endl;
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> p >> y >> t;
    ll lo = 1, hi = t;
    ll ans = t;
    while (lo <= hi){
        ll mid = (lo+hi)/2;
        if (valid(mid,pp)){
            ans = mid;
            hi = mid-1;
        } else {
            lo = mid+1;
        }
    }
    cout << ans << "\n";
}