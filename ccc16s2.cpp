#include <bits/stdc++.h>
using namespace std;
int choice, N;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> choice;
    cin >> N;
    vector<int> v1(N), v2(N);
    for (int i = 0; i < N; i++) cin >> v1[i];
    for (int i = 0; i < N; i++) cin >> v2[i];
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    if (choice == 2) reverse(v2.begin(), v2.end());
    int ans = 0;
    for (int i = 0; i < N; i++){
        ans += max(v1[i], v2[i]);
    }
    cout << ans << "\n";
}