#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

unordered_map<char, int> m1, m2;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s1, s2;
    cin >> s1 >> s2;
    int N = s1.length();
    for (int i = 0 ; i < N ; i++){
        m1[s1[i]]++;
        m2[s2[i]]++;
    }
    bool ana = true;
    int ans = 0;
    for (auto i: m1){
        if (m1[i.first] - m2[i.first] < 0) {ana = false; break;}
        else ans += m1[i.first] - m2[i.first];
    }
    if (ana && ans == m2['*']) cout << "A" << "\n";
    else cout << "N\n";
}