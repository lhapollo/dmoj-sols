#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int main(){
    unordered_set<string> st;
    ios_base::sync_with_stdio(true);
    cin.tie(0);
    string t, s;
    cin >> t >> s;
    int n = s.length();
    string s1 = "", s2 = "";
    for (int i = n; i > 0; i--){
        //cout << i << "\n";
        s1 = s.substr(0, i);
        s2 = s.substr(i);
        string s3 = s2+s1;
        //cout << s3 << "\n";
        st.insert(s3);
    }
    bool b = false;
    for (auto i: st){
        if (t.find(i) != std::string::npos){
            b = true;
            break;
        }
    }
    cout << (b? "yes":"no") << "\n";
}