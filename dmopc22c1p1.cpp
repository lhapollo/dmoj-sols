#include <bits/stdc++.h>
using namespace std;
int T;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (cin >> T; T > 0; T--){
        int n;
        cin >> n;
        vector<int> v(n), v2(n); 
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            v2[i] = v[i];
        }
       bool updown = true;
       for (int i = 1; i < n; i+=2){
            if (v[i] == 0) v[i] = INT_MAX;
       }
       for (int i = 1; i < n; i+= 2){
            if (v[i-1] >= v[i] || (i+1 < n && v[i] <= v[i+1])) updown = false;
       }
       bool downup = true;
       for (int i = 0; i < n; i+= 2){
            if (v2[i] == 0) v2[i] = INT_MAX;
       }
       for (int i = 0; i < n; i+= 2){
            if ((i-1 >= 0 && v2[i-1] >= v2[i]) || (i+1 < n && v2[i] <= v2[i+1])) downup = false;
       }
       cout << ((downup || updown)? "YES\n":"NO\n");
    }
}

