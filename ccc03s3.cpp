#include <bits/stdc++.h>
using namespace std;

char m[26][26];
vector<int> room;
int area = 0, wood = 0, r = 0, c = 0;
void flood(int x, int y){
    area++;
    m[x][y] = 'I'; //marks as visited
    if (x-1 >= 1 && m[x-1][y] == '.') flood(x-1, y);
    if (y-1 >= 1 && m[x][y-1] == '.') flood(x, y-1);
    if (x+1 <= r && m[x+1][y] == '.') flood(x+1, y);
    if (y+1 <= c && m[x][y+1] == '.') flood(x, y+1);
}

int main(){
    cin >> wood >> r >> c;
    for (int i = 1; i <= r; i++){
        for (int j = 1; j <= c; j++){
            cin >> m[i][j];
        }
    }
    for (int i = 1; i <= r; i++){
        for (int j = 1; j <= c; j++){
            if (m[i][j] == '.'){
                area = 0;
                flood(i, j);
                room.push_back(area);
            }
        }
    }
    int ans = 0;
    sort(room.begin(), room.end(), greater<int>());
    for (auto i = room.begin(); i != room.end() && wood >= *i; i++){
        wood -= *i; 
        ans++;
    }
    cout << ans << (ans == 1? " room, ": " rooms, ");
    cout << wood << " square metre(s) left over\n";
    return 0;
}