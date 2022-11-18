#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<double> v(n,0);
    double start = 1.0;
    for (int i = 0; i < n; i++){
        int a, p;
        cin >> a >> p;
        double temp = start * p/100.0;
        start -= temp;
        v[a-1] += temp;
    }
    for (auto i: v) printf("%.6f\n", i);
}