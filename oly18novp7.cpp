#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define HI 100000 

int dist[HI + 1];
bool visited[HI + 1];

int main(){
    ios_base::sync_with_stdio();
    cin.tie(0);
    int start, end;
    cin >> start >> end;
    memset(visited, false, sizeof(visited));
    memset(dist, INF, sizeof(dist));
    dist[start] = 0;
    visited[start] = true;
    
    queue <int> buff;
    buff.push(start);
    int curr;
    while (!buff.empty()){
        curr = buff.front();
        //cout << curr << endl;
        buff.pop();
        if (curr == end) break;
        int behind = curr - 1;
        int ahead = curr+1;
        int jump = curr * 2;
        if (behind >= 0 && behind <= HI && !visited[behind] && dist[behind] == INF){
            //cout << "add behind: " << behind <<  endl;
            dist[behind] = dist[curr] +1;
            visited[behind] = true;
            buff.push(behind);
            //cout << "distance: " << dist[behind] << endl;
        }
        if (ahead >= 0 && ahead <= HI && !visited[ahead] && dist[ahead] == INF){
            //cout << "add ahead: " << ahead <<  endl;
            dist[ahead] = dist[curr] +1;
            visited[ahead] = true;
            buff.push(ahead);
            //cout << "distance: " << dist[ahead] << endl;
        }
        if (jump >= 0 && jump <= HI && !visited[jump] && dist[jump] == INF){
            //cout << "add jump: " << jump <<  endl;
            dist[jump] = dist[curr] +1;
            visited[jump] = true;
            buff.push(jump);
            //cout << "distance: " << dist[jump] << endl;
        }
    }
    cout << dist[end] << "\n";
}