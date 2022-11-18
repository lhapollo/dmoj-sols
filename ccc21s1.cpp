#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> lens(n+1);
    vector<int> wid(n);
    for (int i = 0; i <= n; i++) cin >> lens[i];
    for (int i = 0; i < n; i++) cin >> wid[i];
    double ans = 0.0;
    for (int i = 0; i < n; i++){
        ans += (((lens[i]+lens[i+1])*wid[i])/2.0);
    }
    printf("%.6f\n", ans);
}