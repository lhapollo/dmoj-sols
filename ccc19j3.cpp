#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;
int N;

int main(){
    ios_base::sync_with_stdio();
    cin.tie(0);
    for (cin >> N; N > 0; N--){
        string s;
        cin >> s;
        int curr = 1;
        char prev = s[0];
        for (int i = 1; i < s.length(); i++){
            if (s[i] == prev) curr++;
            else {
                cout << curr << " " << prev << " ";
                curr = 1;
                prev = s[i];
            } 
        }
        cout << curr << " " << prev << "\n";
    }
}