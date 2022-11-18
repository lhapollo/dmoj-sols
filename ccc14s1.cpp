#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int k;
    cin >> k;
    int m;
    cin >> m;
    vector<int> v;
    for (int i = 1; i<= k; i++) v.push_back(i);
    for (int i = 0; i < m; i++){
        int r;
        cin >> r;
        for (int i = r-1; i < v.size(); i+= r){
            v[i] = -1;
        }
        for (int i = 0; i < v.size(); i++){
            if (v[i] == -1) {v.erase(v.begin()+i);i--;continue;}
        }
    }
   for (auto i: v) cout << i << "\n";
    
}