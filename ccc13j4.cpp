#include <bits/stdc++.h>
using namespace std;
vector<int> times;
int t, c;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t >> c;
    int x;
    for (int i = 0; i < c; i++){
        cin >> x;
        times.push_back(x);
    }
    int ans = 0;
    sort(times.begin(), times.end());
    for (int i = 0; i < times.size(); i++){
        if (t >= times[i]){
            ans++;
            t -= times[i];
        }
    }
    cout << ans << "\n";
}