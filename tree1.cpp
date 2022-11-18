#include<bits/stdc++.h>
using namespace std;

int graph[4][4];
bool connected[4];

int main(){
    int edge = 0;
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            cin >> graph[i][j];
            if (graph[i][j] == 1) {
                edge++;
                connected[i] = true;
                connected[j] = true;
            }
        }
    }
    cout << ((edge == 6 && connected[0] && connected[1] && connected[2] && connected[3]) ? "Yes":"No") << "\n";
}