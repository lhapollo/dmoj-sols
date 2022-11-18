#include <bits/stdc++.h>
using namespace std;
int G, P, g;
set<int> gates;
vector<int> v;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> G >> P;
    for (int i = G; i >= 1; i--){
        gates.insert(-i);
    }
    int ans = 0;
    for (int i = 0; i < P; i++){
        cin >> g;
        v.push_back(g);
    }
    for (auto x: v){
        auto pos = gates.lower_bound(-x);
        if (pos == gates.end()) break;
        gates.erase(pos);
        ans++;
    }
    cout << ans << "\n";
}