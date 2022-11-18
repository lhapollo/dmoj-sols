#include <bits/stdc++.h>
using namespace std;
int T;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (cin >> T; T > 0; T--){
        int N;
        stack<int> mtn, branch, lake;
        cin >> N;
        for (int i = 0; i < N; i++){
            int x;
            cin >> x;
            mtn.push(x);
        }
        bool valid = true;
        int curr, branchcurr;
        int nxt = 1;
        while (valid){
            if (!mtn.empty()) curr = mtn.top();
            if (!branch.empty()) branchcurr = branch.top();
            //cout << "current car: " << curr << endl;
            if (curr == nxt){
                //cout << curr << " goes straight to lake." << endl;
                lake.push(curr);
                mtn.pop();
                nxt++;
            }
            else if (!branch.empty() && branchcurr == nxt){
                //cout << "push from branch, car: " << branchcurr << endl;
                lake.push(branchcurr);
                branch.pop();
                nxt++;
            }
            else {
                branch.push(curr);
                mtn.pop();
                //cout << curr << " goes to branch." << endl;
            }
            //cout << "next car needed: " << nxt << endl;
            if (mtn.empty() && !branch.empty() && branch.top() != nxt) {valid = false; break;}
            if (mtn.empty() && lake.size() == N) break;
        }
        cout << (valid? "Y":"N") << "\n";
    }
}