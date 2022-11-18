#include <bits/stdc++.h>
using namespace std;
int ans = 1000000000;
int N;
int sour[11], bitter[11];

// recursive method to generate all combinations
void gen(int i, int n, vector<int> &com)
{
    // base
    if (i > n)
    {
        if (com.size() == 0) return;
        int sr = 1, bt = 0;
        for (auto x: com) {
            sr *= sour[x];
            bt += bitter[x];
        }
        ans = min(ans, abs(sr-bt));
        return;
    }
    gen(i + 1, n, com); // skipping i
    {
        // not skipping i
        com.push_back(i);
        gen(i + 1, n, com);
        com.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    vector<int> comb;
    memset(sour, 0, sizeof(sour));
    memset(bitter, 0, sizeof(bitter));
    for (int i = 1; i <= N; i++)
    {
        int s, b;
        cin >> s >> b;
        sour[i] = s;
        bitter[i] = b;
    }
    gen(1, N, comb);
    cout << ans << "\n";
}