#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio();
    cin.tie(0);
    int h = 0, v = 0;
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++){
        if (s[i] == 'V') v++;
        else if (s[i] = 'H') h++;
    }
    v %= 2;
    h %= 2;
    if (v == 1 && h == 0) {
        cout << "2 1" << endl;
        cout << "4 3" << endl;
    } else if (h == 1 && v == 0) {
        cout << "3 4" << endl;
        cout << "1 2" << endl;
    } else if (h == 1 && v == 1){
        cout << "4 3" << endl;
        cout << "2 1" << endl;
    } else if (h == 0 && v == 0){
        cout << "1 2" << endl;
        cout << "3 4" << endl;
    }
}