#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> arr(100001);
ll ans = 0, lo = 0, hi = 0, mid = 0;
int n, m;

//a method to check if it's possible to create at most m subarrays with subarray sums less than val
bool valid(ll val){
    int count = 1; //keeps track of number of subarrays
    ll subArrSum = 0; //keeps track of sum of current subarray.
    for (int i = 1; i <= n; i++){
        //if (arr[i] > val) return false;
        if (subArrSum + arr[i] <= val) subArrSum += arr[i]; //add arr[i] to current subarray, updating the sum of current subarray.
        else {
            //reset, increment number of subarrays by 1. 
            count++;
            subArrSum = arr[i];
        }
    }
    return count <= m;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    //find the maximum possible subarray sum, as well as minimum possible subarray sum.
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
        lo = max(lo, arr[i]);
        hi += arr[i];
        
    }
    //binary search, to find the optimal minimum maximum subarray sum.
    while (lo <= hi){
        mid = (lo+hi)/2;
        //if the middle value can be a possible max subarray sum, it is our new minimum, and our new answer.
        if (valid(mid)){
            ans = mid;
            hi = mid-1;
        }
        else {
            lo = mid+1;
        }
    }
    cout << ans << "\n";
    //return 0;
}
