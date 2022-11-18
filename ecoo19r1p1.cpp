#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio();
    cin.tie(0);
    for (int t = 0; t < 10; t++){
        int n, m, d;
        cin >> n >> m >> d;
        vector<int> days(d, 0);
        for (int i = 0; i < m; i++){
            int day; cin >> day;
            days[day-1]++;
        }

        int curr = n, ans = 0;
        for (int i = 0; i < d; i++){
            if (curr == 0) {
                ans++;
                curr = n;
            }
            n += days[i];
            curr += days[i];
            curr--;
        }
        cout << ans << "\n";
    }
}