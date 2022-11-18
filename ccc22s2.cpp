#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

vector<pair<string, string> > canBeTogether;
vector<pair<string, string> > cantBeTogether;

unordered_map<string, int> nameGroup;

int main(){
    ios_base::sync_with_stdio();
    cin.tie(0);
    int x;
    cin >> x;
    for (int i = 0; i < x; i++){
        string n1, n2;
        cin >> n1 >> n2;
        canBeTogether.push_back(make_pair(n1,n2));
    }
    int y;
    cin >> y;
    for (int i = 0; i < y; i++){
        string n1, n2;
        cin >> n1 >> n2;
        cantBeTogether.push_back(make_pair(n1,n2));
    }
    int g;
    cin >> g;
    for (int i = 1; i <= g; i++){
        string n1, n2, n3;
        cin >> n1 >> n2 >> n3;
        nameGroup[n1] = i;
        nameGroup[n2] = i;
        nameGroup[n3] = i;
    }
    int ans = 0;
    for (auto i: canBeTogether){
        if (nameGroup[i.first] != nameGroup[i.second]) ans++;
    }
    for (auto i: cantBeTogether){
        if (nameGroup[i.first] == nameGroup[i.second]) ans++;
    }
    cout << ans << "\n";
}