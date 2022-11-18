#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll x;
    cin >> x;
    int skip = x / 720;
    int ans = 31 * skip;
    x -= (720 * skip);
    for (int i = 0; i <= x; i++)
    {
        int hr = (i / 60);
        int min = i - (hr * 60);
        switch (hr)
        {
        case 0:
            if (min == 34)
                ans++;
            break;
        case 1:
            if (min == 11 || min == 23 || min == 35 || min == 47 || min == 59) ans++;
            break;
        case 2:
            if (min == 22 || min == 34 || min == 46 || min ==58 || min == 10) ans++;
            break;
        case 3:
            if (min == 33 || min == 45 || min == 57 || min == 21) ans++;
            break;
        case 4:
            if (min == 44 || min == 56 || min == 32 || min == 20) ans++;
            break;
        case 5:
            if (min == 55 || min == 43 || min == 31) ans++;
            break;
        case 6:
            if (min == 54 || min == 42 || min == 30) ans++;
            break;
        case 7:
            if (min == 53 || min == 41) ans++;
            break;
        case 8:
            if (min == 52 || min == 40) ans++;
            break;
        case 9:
            if (min == 51) ans++;
            break;
        case 11:
            if (min == 11) ans++;
            break;
        default:
            break;
        }
    }
    cout << ans << "\n";
}