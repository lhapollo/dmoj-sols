#include <bits/stdc++.h>
using namespace std;

int main(){
    int m, n, k;
    cin >> m >> n >> k;
    vector<int> rows(m), cols(n);
    for (int i = 0; i < k; i++){
        char X;
        int num;
        cin >> X >> num;
        if (X == 'R') rows[num-1] ++;
        else if (X == 'C') cols[num-1]++;
    }

    int ans = 0;
    int rowCount = 0;
    for (auto i: rows) {
        i %= 2;
        if (i == 1) rowCount++;
    }
    ans += rowCount * n;
    int colCount = 0;
    for (auto i: cols){
        i %= 2;
        if (i == 1) colCount++;
    }
    ans += colCount * m;
    ans -= (colCount * rowCount * 2);
    cout << ans <<"\n";
}