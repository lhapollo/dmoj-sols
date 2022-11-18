#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int T;
ll x,y;

/*
minimize the path by greedily dividing by 2 when possible. 
start from x, and continue until x is less than y. 
then start from y and minimize it in the same way. 
note that this does not change the end value of y, but rather finds the minimal end path, and we join the two paths together in the middle. 
*/

int main(){
    ios_base::sync_with_stdio();
    cin.tie(0);
    for (cin >> T; T >0; T--){
        cin >> x >> y;
        if (x == y){cout << 0 <<"\n"; continue;}
        ll step = 0, ans = 1e18;
        while (y >= 1){
            if (x > y){
                if (x % 2 == 1) {x++; step++;}
                x /= 2; step++;
            } else if (x < y) {
                ans = min(ans, step + (y-x));
                if (y % 2 ==1){y--; step++;}
                y /= 2; step++;
            } else {ans = min(ans, step); break;}
        }
        cout << ans <<"\n";
    }
}