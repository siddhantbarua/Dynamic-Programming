#include<bits/stdc++.h>

using namespace std;

long long gridTraveller(int m, int n){
    vector<vector<long long>> table(m + 1, vector<long long>(n + 1, 0));

    table[1][1] = 1;

    for (int i = 0; i <= m; i++){
        for (int j = 0; j <= n; j++){
            if (j + 1 <= n){
                table[i][j + 1] += table[i][j];
            }
            if (i + 1 <= m){
                table[i + 1][j] += table[i][j];
            }
        }
    }

    return table[m][n];
}

int main(){
    cout << gridTraveller(18, 18);
    return 0;
}
