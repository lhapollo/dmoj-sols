#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

bool unique(int num){
    stringstream ss;
    ss << num;
    string res = ss.str();
    unordered_set<char> digs;
    for (int i = 0; i < res.length(); i++){
        digs.insert(res[i]);
    }
    return (digs.size() == res.length());
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int year;
    cin >> year;
    year++;
    while (true){
        if (unique(year)) break;
        else year++;
    }
    cout << year << "\n";
}