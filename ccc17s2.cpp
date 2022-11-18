#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> up, down;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    if (n % 2 == 1)
    {
        for (int i = 0; i <= n / 2; i++)
        {
            down.push_back(v[i]);
        }
        for (int i = n - 1; i > n / 2; i--)
        {
            up.push_back(v[i]);
        }
    }
    else
    {
        for (int i = 0; i < n / 2; i++)
        {
            down.push_back(v[i]);
        }
        for (int i = n - 1; i >= n / 2; i--)
        {
            up.push_back(v[i]);
        }
    }

    reverse(down.begin(), down.end());
    reverse(up.begin(), up.end());
    // for (auto i : up)
    //     cout << i << " ";
    // cout << endl;
    // for (auto i : down)
    //     cout << i << " ";
    // cout << endl;
    if (n % 2 == 0){
        for (int i = 0; i < n / 2; i++){
            cout << down[i] << " " << up[i] << " ";
        } cout << "\n";
    } 
    else {
        for (int i = 0; i < n/2; i++){
            cout << down[i] << " " << up[i] << " ";
        }
        cout << down[(n/2)] << "\n";
    }
}