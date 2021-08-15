#include<bits/stdc++.h>

using namespace std;

int fib(int n){
    vector<int> table(n + 3, 0);

    if (n >= 1){
        table[1] = 1;
    }

    if (n >= 2){
        for (int i = 0; i <= n; i++){
            table[i + 1] += table[i];
            table[i + 2] += table[i];
        }
    }

    return table[n];
}

int main(){
    cout << fib(6);
    return 0;
}
