#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
unordered_map<int, int> jerseys;

int convert(char c){
    if (c == 'S') return 1;
    if (c == 'M') return 2;
    if (c == 'L') return 3;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int j, a;
    cin >> j >> a;
    for (int i = 1; i <= j; i++){
        char c;
        cin >> c;
        int num = convert(c);
        jerseys[i] = num;
    }
    char x;
    int y;
    int ans = 0;
    for (int q = 0; q < a; q++){
        cin >> x >> y;
        int num = convert(x);
        if (jerseys[y] >= num) {
            ans++;
            jerseys[y] = -1;
        }
    }
    cout << ans << "\n";
}