#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int> > pq;
vector<pair<int, int> > houses;
int N, M, T;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> T;
    for (int i = 0; i < N; i++){
        int p, c;
        cin >> p >> c;
        houses.push_back(make_pair(p,c));
    }
    long long sum = 0;
    sort(houses.begin(),houses.end());
    int numHouses = 0;
    long long ans = 0;
    for (int i = 0; i < N; i++){
        if (houses[i].first*2 + T > M) break;
        sum += houses[i].second; pq.push(houses[i].second);
        int k = (M-2*houses[i].first)/T;
        while (pq.size() > k){
            sum -= pq.top(); pq.pop();
        }
        ans = max(ans, sum);
    }
    cout << ans << "\n";
}
