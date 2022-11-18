#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio();
    cin.tie(0);
    int n;
    cin >> n;
    int sx = 99999, sy = 99999, lx = -1, ly = -1; 
    for (int i = 0; i < n; i++){
        char comma;
        int x, y;
        cin >> x >> comma >> y;
        sx = min(sx, x);
        lx = max(lx, x);
        sy = min(sy, y);
        ly = max(ly, y);
    }
    cout << sx-1 << "," << sy-1 << "\n";
    cout << lx+1 << "," << ly+1 <<"\n";
}