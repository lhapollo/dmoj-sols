#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x);
#define swap(v,l,r) reverse(v.begin()+l,v.begin()+r); 
#define show(v) for (auto i: v) {cout << i << " ";} cout << "\n";
vector<int> v;

bool og(vector<int> v){
    for (int i = 1; i <= v.size(); i++){
        if (v[i-1] != i) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) v.pb(i);
    int a1, a2, b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;
    int cycle = 0;
    while (true){
        swap(v, a1-1, a2);
        //show(v);
        swap(v, b1-1, b2);
        //show(v);
        cycle++;
        if (og(v)) break;
    }
    k %= cycle;
    for (int i = 0 ; i < k; i++){
        swap(v,a1-1, a2);
        swap(v,b1-1,b2);
    }
    for (auto i: v) cout << i << "\n";
}