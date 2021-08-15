#include<unordered_map>
#include<iostream>

using namespace std;

int fibonacci(long long n, unordered_map<int, long long>& mp){     
    if (n <= 2){
        return 1;
    }

    if (mp.find(n) != mp.end()){
        return mp[n];
    }

    mp[n] = fibonacci(n - 1, mp) + fibonacci(n - 2, mp);

    return mp[n];
}

int main(){
    long long num;
    unordered_map<int, long long> mp;
    cin >> num;
    cout << fibonacci(num, mp);
    return 0;
}
