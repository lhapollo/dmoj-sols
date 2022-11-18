#include <bits/stdc++.h>
using namespace std;

bool bad[21][21];
int n, m;
int ans;

//recursive method to generate all combinations
void gen(int i, int n, vector<int>& com){
    //base
    if (i > n) {ans++; return;}
    gen(i+1, n, com); //skipping i
    bool conflict = 0;
    for (auto x: com) if(bad[x][i]) conflict = 1;
    if (!conflict){
        //not skipping i
        com.push_back(i);
        gen(i+1, n, com);
        com.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int> com;
    memset(bad, 0, sizeof(bad));
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        bad[a][b] = bad[b][a] = 1;
    }
    gen(1, n, com);
    cout << ans << "\n";
}