#include <bits/stdc++.h>
using namespace std;
vector<int> v;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    v.resize(N);
    for (int i = 0; i < N; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    double ans = 1000000000.0;
    for (int i = 1; i < N-1; i++){
        double a = v[i], b = v[i-1], c = v[i+1];
        double tot = ((a-b)/2.0) + ((c-a)/2.0);
        ans = min(ans, tot);
    }
    printf("%.1f\n", ans);
}