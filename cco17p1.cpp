#include <bits/stdc++.h>
using namespace std;

vector<int> paircount;

void print_cycle(int start, int end){
    if (end-start == 1){
        cout << start << " " << end << "\n";
        cout << end << " " << start << "\n";
    } else{
        for (int i = start; i < end; i++){
            cout << i << " " << i+1 << "\n";
        }
        cout << end << " " << start << "\n";
    }
    
}

int main(){
    for (int i = 0; i <= 5000; i++){
        paircount.push_back((i*(i-1))/2);
    }
    int k; cin >> k;
    
    vector<pair<int,int> > cycles;

    int start = 1;

    while (k > 0){
        int ind = upper_bound(paircount.begin(), paircount.end(), k) - paircount.begin();
        //cout << paircount[ind-1] << endl;
        cycles.push_back(make_pair(start, start + ind-2));
        start += ind-1;
        k -= paircount[ind-1];
    }
    //for (auto i: cycles) cout << i.first << " " << i.second << endl;

    int n = cycles.size();
    cout << cycles[n-1].second << " " << cycles[n-1].second + n-1 << "\n";
    int x = cycles[0].second;
    int y = cycles[1].first;
    for (int i = 1 ; i <= n; i++){
        x = cycles[i-1].second;
        y = cycles[i].first;
        print_cycle(cycles[i-1].first, cycles[i-1].second);
        if (i != n) cout << x << " " << y << "\n";
    }
    // for (auto i: cycles){
    //      print_cycle(i.first, i.second);
    // }
}