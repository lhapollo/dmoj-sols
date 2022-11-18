#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
char adj[51][51];
int floodcheck[51][51];
int dist[51][51];
bool vis[51][51];

bool valid(int x, int y, int r, int c){
    return (x >= 1 && x <= r && y >= 1 && y <= c);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int r, c;
    cin >> r >> c;
    int endr, endc, startr, startc;
    queue<pi> q;
    for (int i = 1; i <= r; i++){
        for (int j = 1; j <= c; j++){
            cin >> adj[i][j];
            vis[i][j] = 0;
            dist[i][j] = -1;
            if (adj[i][j] == '*') {floodcheck[i][j] = 0; q.push(make_pair(i,j));vis[i][j] = 1;}
            if (adj[i][j] == 'S') {floodcheck[i][j] = INT_MAX; startr = i; startc = j;}
            if (adj[i][j] == 'D') {floodcheck[i][j] = INT_MAX; endr = i; endc = j;}
            if (adj[i][j] == '.') floodcheck[i][j] = INT_MAX;
        }
    }
    pi curr;
    // for (int i = 1; i <= r; i++){
    //     for (int j = 1; j <= c; j++){
    //         cout << floodcheck[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    while (!q.empty()){
        curr = q.front();
        q.pop();
        int x = curr.first, y = curr.second;
        if (valid(x-1,y,r,c) && !vis[x-1][y] && floodcheck[x-1][y] == INT_MAX && adj[x-1][y] == '.'){
            vis[x-1][y] = 1;
            floodcheck[x-1][y] = floodcheck[x][y] + 1;
            q.push(make_pair(x-1,y));
        }
        if (valid(x+1,y,r,c) && !vis[x+1][y] && floodcheck[x+1][y] == INT_MAX && adj[x+1][y] == '.'){
            vis[x+1][y] = 1;
            floodcheck[x+1][y] = floodcheck[x][y] + 1;
            q.push(make_pair(x+1,y));
        }
        if (valid(x,y-1,r,c) && !vis[x][y-1] && floodcheck[x][y-1] == INT_MAX && adj[x][y-1] == '.'){
            vis[x][y-1] = 1;
            floodcheck[x][y-1] = floodcheck[x][y] + 1;
            q.push(make_pair(x,y-1));
        }
        if (valid(x,y+1,r,c) && !vis[x][y+1] && floodcheck[x][y+1] == INT_MAX && adj[x][y+1] == '.'){
            vis[x][y+1] = 1;
            floodcheck[x][y+1] = floodcheck[x][y] + 1;
            q.push(make_pair(x,y+1));
        }
    }
    memset(vis,0,sizeof(vis));
    vis[startr][startc] = 1;
    q.push(make_pair(startr,startc));
    dist[startr][startc] = 0;
    while(!q.empty()){
        curr = q.front();
        q.pop();
        int x = curr.first, y = curr.second;
        if (valid(x,y-1,r,c) && !vis[x][y-1] && dist[x][y-1] == -1 && (floodcheck[x][y-1] != -1 && floodcheck[x][y-1] > dist[x][y]+1) && adj[x][y-1] != 'X'){
            vis[x][y-1] = 1;
            dist[x][y-1] = dist[x][y] + 1;
            q.push(make_pair(x,y-1));
        }
        if (valid(x,y+1,r,c) && !vis[x][y+1] && dist[x][y+1] == -1 && (floodcheck[x][y+1] != -1 && floodcheck[x][y+1] > dist[x][y]+1) && adj[x][y+1] != 'X'){
            vis[x][y+1] = 1;
            dist[x][y+1] = dist[x][y] + 1;
            q.push(make_pair(x,y+1));
        }
        if (valid(x-1,y,r,c) && !vis[x-1][y] && dist[x-1][y] == -1 && (floodcheck[x-1][y] != -1 && floodcheck[x-1][y] > dist[x][y]+1) && adj[x-1][y] != 'X'){
            vis[x-1][y] = 1;
            dist[x-1][y] = dist[x][y] + 1;
            q.push(make_pair(x-1,y));
        }
        if (valid(x+1,y,r,c) && !vis[x+1][y] && dist[x+1][y] == -1 && (floodcheck[x+1][y] != -1 && floodcheck[x+1][y] > dist[x][y]+1) && adj[x+1][y] != 'X'){
            vis[x+1][y] = 1;
            dist[x+1][y] = dist[x][y] + 1;
            q.push(make_pair(x+1,y));
        }
    }
    if (dist[endr][endc] == -1) cout << "KAKTUS\n";
    else cout << dist[endr][endc] << "\n";
    // for (int i = 1; i <= r; i++){
    //     for (int j = 1; j <= c; j++){
    //         cout << dist[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}