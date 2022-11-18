#include <bits/stdc++.h>
using namespace std;
int n;
int arr [101][101];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++) cin >> arr[i][j];
    }
    bool incRIGHT = true, incDOWN = true;
    for (int i = 2; i <= n; i++){
        if (arr[1][i] < arr[1][i-1]){incRIGHT = false;}
        if (arr[i][1] < arr[i-1][1]){incDOWN = false;}
    }
    //cout << incRIGHT << " " << incDOWN << endl;
    if (incRIGHT && incDOWN){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                cout << arr[i][j] << " ";
            }
            cout << "\n";
        }
    } else if (!incRIGHT && incDOWN){
        for (int i = n; i >= 1; i--){
            for (int j = 1; j <= n; j++){
                cout << arr[j][i] << " ";
            }
            cout << "\n";
        }
    } else if (!incRIGHT && !incDOWN){
        for (int i = n; i >= 1; i--){
            for (int j = n; j >= 1; j--){
                cout << arr[i][j] << " ";
            }
            cout << "\n";
        }
    } else if (incRIGHT && !incDOWN){
        for (int i = 1; i <= n; i++){
            for (int j = n; j >= 1; j--){
                cout << arr[j][i] << " ";
            }
            cout << "\n";
        }
    }
}