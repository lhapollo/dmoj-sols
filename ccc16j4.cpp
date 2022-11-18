#include <bits/stdc++.h>
using namespace std;  

//speed = 2 m/min (normal)
//speed = 1 m/min (rush hour)
//distance = 240
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int hr, min;
    char colon;
    cin >> hr >> colon >> min;
    int dist = 0;
    while (dist < 240) {
        //rush hour
        if ((hr >= 7 && hr < 10) ||(hr >= 15 && hr < 19))dist++;
        else dist += 2;
        min++;
        if (min == 60) {hr++; min = 0;}
        if (hr == 24){hr = 0;}
    }
    if (hr < 10) cout << "0" << hr << ":";
    else cout << hr << ":";
    if (min < 10) cout << "0"<< min;
    else cout << min << "\n";

}