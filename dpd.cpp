#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, w;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> w;
    int val[n], wt[n];
    for (int i = 0; i < n; i++){
        cin >> wt[i] >> val[i];
    }
    ll mat[n+1][w+1];
    for (int i = 0; i <= n; i++){
        mat[i][0] = 0;
    }
    for (int i = 0; i <= w; i++){
        mat[0][i] = 0;
    }
    for (int i = 1; i <= n; i++){
        for (int c = 1; c <= w; c++) {
            ll x = mat[i-1][c];
            ll y = 0;
            ll z = wt[i-1];
            if (c >= z){
                y = val[i-1];
                ll left = c-z;
                y += mat[i-1][left];
            }
            mat[i][c] = max(x,y);
        }
    }
    cout << mat[n][w] << "\n";
}