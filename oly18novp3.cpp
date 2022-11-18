#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll ans = 10e14;
vector<ll> arr(100001);
int n, m;

bool valid(ll mid, vector<ll>& arr, int n, int m){
    int count = 0;
    ll sum = 0;
    for (int i = 1; i <= n; i++){
        if (arr[i] > mid){
            return false;
        }
        sum += arr[i];
        if (sum > mid){
            count++;
            sum = arr[i];
        }
    }
    
    count++;
    if (count <= m){
        return true;
    }
    return false;
}

ll solve(vector<ll>& arr, int n, int m){
    ll hi = max_element(arr.begin(), arr.end())-arr.begin();
    ll start = hi;
    ll end = 0;
    for (int i = 1; i <= n; i++){
        end += arr[i];
    }
    ll ans = 0;
    while (start <= end){
        ll mid = (start+end)/2;
        if (valid(mid,arr,n,m)){
            ans = mid;
            end = mid-1;
        } else{
            start = mid+1;
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    cout << solve(arr,n,m);
}