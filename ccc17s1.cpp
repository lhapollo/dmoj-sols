#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> a(N), b(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> b[i];
    }
    int ans = 0;
    int t = 0, v = 0;
    for (int i = 0; i < N; i++){
        t += a[i];
        v += b[i];
        if (t == v) ans = i+1;
    }
    cout << ans << "\n";
}