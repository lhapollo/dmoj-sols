#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

unordered_map<int, int> mymap;
vector<int> times;

int main(){
    ios_base::sync_with_stdio(true);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int t, x;
        cin >> t >> x;
        mymap[t] = x;
        times.push_back(t);
    }
    sort(times.begin(), times.end());
    double ans = 0.0;
    for (int i = 1; i < times.size(); i++){
        double a = mymap[times[i-1]], b = mymap[times[i]];
        int time = times[i] -times[i-1];
        double dist = abs(b-a) *1.0;
        ans = max(ans, dist/(time*1.0));
        //cout << dist/(time*1.0)<< "\n";
    }
    printf("%.5f", ans);
}