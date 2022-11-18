#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio();
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> flowers(n);
    vector<int> psa(n+1);
    for (int i = 0; i < n; i++){
        cin >> flowers[i];
    }
    psa[0] = 0;
    for (int i = 1; i <= n; i++){
        psa[i] = flowers[i-1] + psa[i-1];
    }
    int ans = n;
    for (int i = 1; i < n; i++){
        for (int j = i+1; j <= n; j++){
            int tot = psa[j] - psa[i-1];
            double avg = (tot *1.0) / (j-i+1);
            for (int k = i-1; k < j; k++){
                if (flowers[k] == avg){
                    ans++;
                    break;
                }
            }
        }
    }
    cout << ans << "\n";

}