#include <bits/stdc++.h>
using namespace std;
char m[36][51];
int r, c;
bool monkey = false;

void flood(int x, int y){
    if (m[x][y] == 'M') monkey = true;
    m[x][y] = '#';
    //cout << monkey << "\n";
    if (x-1 >= 1 && (m[x-1][y] == '.' || m[x-1][y] == 'M')) flood(x-1, y);
    if (x+1 <= r && (m[x+1][y] == '.' || m[x+1][y] == 'M')) flood(x+1, y);
    if ((m[x][y-1] == '.' || m[x][y-1] == 'M') && y-1 >= 1) flood(x, y-1);
    if ((m[x][y+1] == '.'|| m[x][y+1] == 'M') && y+1 <= c) flood(x, y+1);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(m, '#', sizeof(m));
    cin >> r >> c;
    for (int i = 1; i <= r; i++){
        for (int j = 1; j <= c; j++){
            cin >> m[i][j];
        }
    }
    int ans = 0;
    for (int i = 1; i <= r; i++){
        for (int j = 1; j <= c; j++){
            if (m[i][j] == '.' || m[i][j] == 'M') {
                monkey = false;
                flood(i, j);
                if (monkey) ans++;
            }
        }
    }
    cout << ans << "\n";
}