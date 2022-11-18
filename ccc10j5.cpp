#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
bool adj[9][9];
int dist[9][9];

/*
(a+1, b+2), (a+1, b-2)
(a-1, b+2), (a-1, b-2)
(a+2, b+1), (a+2, b-1)
(a-2, b+1), (a-2, b-1)
*/

bool valid(int x, int y){
    return (x >=1 && x <= 9 && y <= 9 && y >=1);
}
bool check(int x, int y){
    if (valid(x,y) && !adj[x][y] && dist[x][y] == INF){
        return true;
    } return false;
}
int main(){
    memset(adj, false, sizeof(adj));
    memset(dist,INF, sizeof(dist));
    ios_base::sync_with_stdio(true);
    cin.tie(0);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    queue<pair<int, int> > buff;
    pair<int, int> start(a, b);
    pair<int, int> curr; 
    buff.push(start);
    adj[a][b] = true;
    dist[a][b] = 0;
    while (!buff.empty()){
        curr = buff.front();
        buff.pop();
        //cout << curr.first << " " << curr.second << endl;
        int x = curr.first;
        int y = curr.second;
        if (x == c && y == d) break;
        int a1 = x+1, a2 = x-1, a3 = x+2, a4 = x-2;
        int b1 = y+1, b2 = y-1, b3 = y+2, b4 = y-2;
        if (check(a1, b3)){
            dist[a1][b3] = dist[x][y] + 1;
            buff.push(make_pair(a1, b3));
        } 
        if (check (a1, b4)){
            dist[a1][b4] = dist[x][y] + 1;
            buff.push(make_pair(a1, b4));
        }
        if (check (a2, b3)){
            dist[a2][b3] = dist[x][y] +1;
            buff.push(make_pair(a2, b3));
        }
        if (check (a2, b4)){
            dist[a2][b4] = dist[x][y] +1;
            buff.push(make_pair(a2, b4));
        }
        if (check (a3, b1)){
            dist[a3][b1] = dist[x][y] +1;
            buff.push(make_pair(a3, b1));  
        }
        if (check(a3, b2)){
            dist[a3][b2] = dist[x][y] +1; 
            buff.push(make_pair(a3, b2));   
        }
        if (check(a4, b1)){
            dist[a4][b1] = dist[x][y] +1;
            buff.push(make_pair(a4, b1)); 
        }
        if (check(a4, b2)){
            dist[a4][b2] = dist[x][y] +1;
            buff.push(make_pair(a4, b2));
        }
    }
    cout << dist[c][d] <<"\n";
}