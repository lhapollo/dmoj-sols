#include <bits/stdc++.h>
using namespace std;

bool isMonkey(string s);

bool isA(string s){
    if (s == "A") return true;
    int n = s.length();
    if (n > 1 && s[0] == 'B' && s[n-1] == 'S' && isMonkey(s.substr(1, n-2))) return true;
    return false;
}

bool isMonkey(string s){
    if (isA(s)) return true;
    else {
        for (int i = 1; i < s.length(); i++){
            string before = s.substr(0, i);
            string after = s.substr(i+1);
            if (s[i] == 'N' && isA(before) && isMonkey(after)) return true;
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s = "";
    while (s != "X"){
        cin >> s;
        if (s == "X") break;
        cout << (isMonkey(s)? "YES":"NO") << "\n";
    }
}