#include <bits/stdc++.h>
using namespace std;

vector<int> lnk(100001);
vector<int> sze(100001);
int N, Q;

int find(int x){
    while (x != lnk[x]) x = lnk[x];
    return x;
}

bool same(int a, int b) {return (find(a) == find(b));}

void unite(int a, int b){
    a = find(a);
    b = find(b);
    if (sze[a] < sze[b]) swap(a,b);
    sze[a] += sze[b];
    lnk[b] = a;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> Q;
    for (int i = 1; i <= N; i++){
        lnk[i] = i;
    }
    for (int i = 1; i <= N; i++){
        sze[i] = 1;
    }
    for (int i = 1; i <= Q; i++){
        char q; int a, b;
        cin >> q >> a >> b;
        if (q == 'A') {unite(a,b);}
        else if (q == 'Q') {
            cout << (same(a,b)?"Y":"N") << "\n";
        }
    }
}