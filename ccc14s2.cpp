#include <bits/stdc++.h>
#include <unordered_map>

typedef std::map<std::string, std::string> mss;
typedef std::vector<std::string> vs;

using namespace std;

mss partners;
vs v1, v2;
int N;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++){
        string name;
        cin >> name;
        v1.push_back(name);
    }
    for (int i = 0; i < N; i++){
        string name;
        cin >> name;
        v2.push_back(name);
    }
    for (int i = 0; i < N; i++){
        partners[v1[i]] = v2[i];
    }
    bool good = true;
    for (auto i: partners){
        string a = i.first, b = i.second;
        if (a == b || partners[b] != a) {good = false; break;}
    }
    cout << (good?"good":"bad") << "\n";
}