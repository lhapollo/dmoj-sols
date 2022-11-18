#include <bits/stdc++.h>
using namespace std;
vector<int> sieve(10000001,0);

bool isPrime(int x){
    if (x == 1) return false;
    for (int i = 2; i <= sqrt(x); i++){
        if (x % i == 0) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 1; i <= 10000000; i++){
        if (isPrime(i)){
            for (int j = i; j <= 10000000; j+= i) sieve[j]++;
        }
    }
    //for (int i = 1; i <= 10; i++) cout << sieve[i] << endl;
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++){
        int a, b, c;
        cin >> a >> b >> c;
        int ans = 0;
        for (int j = a; j <= b; j++){
            if (sieve[j] == c) ans++;
        }
        cout << "Case #" << i <<": " << ans << "\n";
    }
}