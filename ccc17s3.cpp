#include <bits/stdc++.h>
#include <unordered_map>
using namespace std; 

int N, X;
int sums[4001];
unordered_map<int, int> freq;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(sums, 0, sizeof(sums));
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> X;
        freq[X]++;
    }
    for (int i = 1; i <= 2000; i++){
        for (int j = i; j <= 2000; j++){
            int a = freq[i], b = freq[j];
            if (a == 0 || b == 0) continue;
            else {
                // cout << i << " " << j <<"\n";
                // cout << a << " " << b <<"\n";
                // cout << "i+j = " << i+j << "\n";
                
                if (i == j){
                    sums[i+j] += a/2;
                } else {
                    sums[i+j] += min(a, b);
                }
                // cout << "sums["<<i+j <<"] = " << sums[i+j] << "\n";
                // cout << "--------------------------------\n";
            }
        }
    }
    // for (int i = 1; i <= 4000; i++){
    //     sums[i] /= 2;
    // }
    int ans1 = 0, ans2 = 0;
    for (int i = 1; i <= 4000; i++){
        if (sums[i] > ans1){
            ans1 = sums[i];
            ans2 = 1;
        } else if (sums[i] == ans1){
            ans2++;
        }
    }
    cout << ans1 << " " << ans2;
}