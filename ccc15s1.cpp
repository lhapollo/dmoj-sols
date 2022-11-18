#include <bits/stdc++.h>
#include <stack>
using namespace std;
stack<int> s;
int k;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> k;
    for (int i = 0; i < k; i++){
        int num;
        cin >> num;
        if (num != 0) s.push(num);
        else s.pop();
    }
    int ans = 0;
    while (!s.empty()){
        int curr = s.top();
        s.pop();
        ans += curr;
    }
    cout << ans << "\n";
}