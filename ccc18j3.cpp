#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << "0 " << a << " " << a+b << " " << a+b+c << " " << a+b+c+d << "\n";
    cout << a << " 0 " << b << " " << b+c << " " << b+c+d << "\n";
    cout << a+b << " " << b << " 0 " << c << " " << c+d << "\n";
    cout << a+b+c << " " << b+c << " " << c << " 0 " << d <<"\n";
    cout << a+b+c+d << " " << b+c+d << " " << c+d << " " << d << " 0\n";
}