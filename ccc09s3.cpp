#include <bits/stdc++.h>
using namespace std;
int adj[51][51];
bool taken[51];
int dist[51];
#define INF 0x3f3f3f3f
char c;
int a, b;

int main(){
    //graph
    adj[1][6] = adj[6][1] = 1;
    adj[2][6] = adj[6][2] = 1;
    adj[3][6] = adj[6][3] = 1;
    adj[4][6] = adj[6][4] = 1;
    adj[5][6] = adj[6][5] = 1;
    adj[7][6] = adj[6][7] = 1;
    adj[3][4] = adj[4][3] = 1;
    adj[3][5] = adj[5][3] = 1;
    adj[3][15] = adj[15][3] = 1;
    adj[4][5] = adj[5][4] = 1;
    adj[7][8] = adj[8][7] = 1;
    adj[8][9] = adj[9][8] = 1;
    adj[9][12] = adj[12][9] = 1;
    adj[9][10] = adj[10][9] = 1;
    adj[10][11] = adj[11][10] = 1;
    adj[11][12] = adj[12][11] = 1;
    adj[12][13] = adj[13][12] = 1;
    adj[13][14] = adj[14][13] = 1;
    adj[13][15] = adj[15][13] = 1;
    adj[16][18] = adj[18][16] = 1;
    adj[16][17] = adj[17][16] = 1;
    adj[17][18] = adj[18][17] = 1;

    while (true){
        cin >> c;
        if (c == 'q')break;
        else if (c == 'i'){
            cin >> a >> b;
            adj[a][b] = 1;
            adj[b][a] = 1;
        } else if (c == 'd'){
            cin >> a >> b;
            adj[a][b] = 0;
            adj[b][a] = 0;
        } else if (c == 'n'){
            cin >> a;
            int ans = 0;
            for (int i = 1; i <= 50; i++){
                if (adj[a][i] == 1) ans++;
            } cout << ans << "\n";
        } else if (c == 'f'){
            cin >> a;
            memset(taken, false, sizeof(taken));
            int ans = 0;
            for (int i = 1; i <= 50; i++){
                if (adj[a][i] == 1){
                    for (int j = 1; j <= 50; j++){
                        if (adj[i][j] == 1 && j != a && adj[a][j] == 0 && !taken[j]) {
                            ans++;
                            taken[j] = true;
                        }
                    }
                }
            }
            cout << ans << "\n";
        } else if (c == 's'){
            //bfs
            cin >> a >> b;
            queue<int> buffer;
            memset(dist, 63, sizeof(dist));
            dist[a] = 0;
            buffer.push(a);
            int curr;
            while (!buffer.empty()){
                curr = buffer.front();
                buffer.pop();
                if (curr == b) break;
                for (int i = 1; i <= 50; i++){
                    if (adj[curr][i] == 1 && dist[i] == INF){
                        dist[i] = dist[curr]+1;
                        buffer.push(i);
                    }
                }
            }
            if (dist[b] == INF) cout << "Not connected\n";
            else cout << dist[b] << "\n";
        }
    }
}