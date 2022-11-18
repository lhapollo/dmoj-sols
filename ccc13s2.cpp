#include <bits/stdc++.h>
using namespace std;
int w, t;
queue<int> carts, bridge;
int currweight = 0;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> w >> t;
    for (int i = 0; i < t; i++){
        int x;
        cin >> x;
        carts.push(x);
    }
    int ans = 0;
    int curr;
    while (!carts.empty()){
        if (bridge.size() < 4){
            curr = carts.front();
            carts.pop();
            if (currweight + curr > w){
                //ans += bridge.size();
                break;
            } else {
                bridge.push(curr);
                currweight += curr;
            }
        } else {
            curr = bridge.front();
            bridge.pop();
            currweight -= curr;
            ans++;
        }
    }
    if (!bridge.empty()) ans += bridge.size();
    cout << ans << "\n";
}