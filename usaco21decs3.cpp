#include <bits/stdc++.h>
using namespace std;

int freq1[5002], freq2[5002];
long long diff[10004];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(freq1, 0, sizeof(freq1));
    memset(freq2, 0, sizeof(freq2));
    memset(diff, 0, sizeof(diff));
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        freq1[a]++;
        freq2[b]++;
    }
    for (int i = 0; i <= m; i++){
        for (int j = 0; j <= m; j++){
            long long temp = 1LL*freq1[i] * freq1[j];
            long long temp2 = 1LL *freq2[i]* freq2[j];
            diff[i+j] += temp;
            diff[i+j+1] -= temp2;
        }
    }
    long long curr = 0;
    for (int i = 0; i <= 2*m; i++){
        curr += diff[i];
        cout << curr << "\n";
    }
}