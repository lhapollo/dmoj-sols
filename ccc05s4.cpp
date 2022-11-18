#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int L, n;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (cin >> L; L > 0; L--){
        unordered_map<string, int> graph;
        vector<string> v;
        int curDepth = 0, maxDepth = 0;
        string name = "";
        cin >> n;
        int ans = n * 10;
        for (int i = n; i > 0; i--){
            cin >> name;
            v.push_back(name);
        }
        //for (auto i: v) cout << i << " ";
        //cout << endl;
        graph[v[n-1]] = 0;
        //cout << "last base: " << v[n-1] << endl;
        for (auto i: v){
            //cout << i << "\n";
            if (graph[i] == 0 && i != v[n-1]){
                //cout << "not found." << "\n";
                curDepth++;
                graph[i] = curDepth;
            } else curDepth--;
            maxDepth = max(maxDepth, curDepth);
            // cout << "curDepth: " << curDepth << "\n";
            // cout << "maxDepth: " << maxDepth << "\n";
        }
        // string name = "";
        // graph["Home"]= 0;
        // cin >> n;
        // int ans = n * 10;
        // for (;n > 0; n--){
        //     cin >> name;
        //     if (graph[name] == 0 && name != "Home"){
        //         curDepth++;
        //         graph[name] = curDepth;
        //     } else curDepth--;
        //     maxDepth = max(maxDepth, curDepth);
        // }
        // cout << maxDepth << "\n";
        // for (auto i: graph){
        //     cout << i.first << " " << i.second << "\n";
        // }
        ans -= (maxDepth * 20);
        cout << ans << "\n";
    }
}