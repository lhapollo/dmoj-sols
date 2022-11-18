#include <bits/stdc++.h>
using namespace std;

int main(){
    int num;
    cin >> num;
    int ans = 0;
    for (int i = 0; 4 * i <= num; i++){
        if ((num - (4*i)) % 5 == 0) ans++;
    }
    cout << ans << "\n";
}