#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > bigArr(100001); //vector of vectors where bigArr[i] contains a vector of all numbers with exactly i factors
vector<int> divisorCount(100001,0); //vector where divisorCount[i] is the number of divisors for element i.

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 1; i <= 100000; i++){
        for (int j = i; j <= 100000; j+= i){
            divisorCount[j]++; //multiples of i, starting at j add a divisor count.
        }
        bigArr[divisorCount[i]].push_back(i);
    }
    int t;
    //lower bound finds first index containing a number <= x. 
    //upper bound finds first index containing a number > x.
    for (cin >> t; t > 0; t--){
        int a, b, c;
        cin >> a >> b >> c;
        int l, r;
        //binary search to find the left and right indices of the range of valid numbers.
        l = lower_bound(bigArr[a].begin(), bigArr[a].end(), b) - bigArr[a].begin();
        r = upper_bound(bigArr[a].begin(), bigArr[a].end(), c) - bigArr[a].begin();
        cout << r - l << "\n";
    }
}