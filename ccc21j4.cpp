#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio();
    cin.tie(0);
    string s;
    cin >> s;
    int L = 0, M = 0, S = 0;
    int n = s.length();
    for (int i = 0; i < n; i++){
        if (s[i] == 'L') L++;
        else if (s[i] == 'M') M++;
        else if (s[i] == 'S') S++;
    }
    int large[] = {0,0,0};
    int med[] = {0,0,0};
    int small[] = {0,0,0};
    int ind = 0;
    for (int i = 0; i < L; i++){
        //cout << s[ind];
        if(s[ind] == 'L') large[0]++;
        else if (s[ind] == 'M')large[1]++;
        else if (s[ind] == 'S')large[2]++;
        ind++;
    }
    for (int i = 0; i < M; i++){
        //cout << s[ind];
        if (s[ind] == 'L') med[0]++;
        else if (s[ind] == 'M') med[1]++;
        else if (s[ind] == 'S') med[2]++;
        ind++;
    }
    for (int i = 0; i < S; i++){
        //cout << s[ind];
        if (s[ind] == 'L') small[0]++;
        else if (s[ind] == 'M') small[1]++;
        else if (s[ind] == 'S') small[2]++;
        ind++;
    }
    int ls = 0, lm = 0, ms = 0;
    int ans = 0;
    ls = min(large[2], small[0]); large[2] -= ls; large[0] += ls; small[0] -= ls; small[2] += ls;
    lm = min(large[1], med[0]); large[1] -= lm; large[0] += lm; med[0] -= lm; med[1] += lm;
    ms = min(small[1], med[2]); med[2] -= ms; med[1] += ms; small[1] -= ms; small[2] += ms;
    ans = ls + lm + ms;
    ans += (large[1] * 2) + (large[2] * 2);
    cout << ans << "\n";

}