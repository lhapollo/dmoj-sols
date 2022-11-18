#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int N, M, W;
bool adj[101][101];
bool car[101], ant[101];
int antDist[101], carDist[101];
queue<int> carBuff, antBuff;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(adj, 0, sizeof(adj));
    memset(ant, 0, sizeof(ant));
    memset(car, 0, sizeof(car));
    memset(antDist, INF, sizeof(antDist));
    memset(carDist, INF, sizeof(carDist));
    cin >> N >> M;
    for (int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }
    cin >> W;
    for (int i = 0; i < W; i++){
        int x;
        cin >> x;
        antBuff.push(x);
        ant[x] = 1;
        antDist[x] = 0;
    }
    int curr;
    while (!antBuff.empty()){
        curr = antBuff.front();
        antBuff.pop();
        for (int i = 1; i <= N; i++){
            if (!ant[i] && adj[curr][i] && antDist[i] == INF){
                ant[i] = 1;
                antDist[i] = antDist[curr] +4;
                antBuff.push(i);
            }
        }
    }
    carBuff.push(1);
    car[1] = 1;
    carDist[1] = 0;
    bool flag = false;
    while (!carBuff.empty()){
        curr = carBuff.front();
        carBuff.pop();
        //cout << curr << endl;
        for (int i = 1; i <= N; i++){
            if (!car[i] && adj[curr][i] && carDist[i] == INF && carDist[curr]+1 < antDist[i]){
                car[i] = 1;
                carDist[i] = carDist[curr] +1;
                carBuff.push(i);
            }
        }
    }
    // for (int i = 1; i <= N; i++) cout << carDist[i] << " ";
    // cout << endl;
    // for (int i = 1; i <= N; i++) cout << antDist[i] << " ";
    if (car[N]) cout << carDist[N];
    else cout << "sacrifice bobhob314\n";
}