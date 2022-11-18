#include <bits/stdc++.h>
using namespace std;
int m;
char c;
int num;
int curr = 0;

vector<int> arr(101, 1), arr2(101), arr3(101);
bool vis[101];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> m;
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < m; i++){
        cin >> c >> num;
        
        if (c != 'W') vis[num] = 1;
        if (c == 'R'){
            arr[num] *= -1; //need reply
            arr3[num] = curr;
            
        } 
        else if (c == 'S'){
            arr[num] *= -1; //got reply
            arr2[num] += curr - arr3[num];
            arr3[num] = 0;
        }
        //cout << curr << endl;
        if (c == 'W') curr += num-1;
        else curr++;
        
    }
    for (int i = 1; i <= 100; i++){
        if (vis[i]){
            cout << i << " " << (arr[i] == -1? -1: arr2[i]) << "\n";
        } 
    }
}