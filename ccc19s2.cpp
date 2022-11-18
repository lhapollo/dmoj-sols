#include <bits/stdc++.h>
using namespace std;
int T;

bool isPrime(int n){
    for (int i = 2; i <= sqrt(n); i++){
        if (n % i == 0) return false;
    } return true;
}

int main(){
    ios_base::sync_with_stdio(true);
    cin.tie(0);
    for (cin >> T; T > 0; T--){
        int n;
        cin >> n;
        n *= 2;
        int a, b;
        for (a = n-2; a >= 2; a--){
            b = n-a;
            if (isPrime(a)&& isPrime(b)){
                cout << a << " " << b << "\n";
                break;
            }
        }
    }
}