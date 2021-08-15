#include<bits/stdc++.h>

using namespace std;

bool canSum(int targetSum, vector<int>& arr, unordered_map<int, bool>& mp){

    if (mp.find(targetSum) != mp.end()){
        return mp[targetSum];
    }

    if (targetSum < 0){
        return false;
    }

    if (targetSum == 0){
        return true;
    }
    
    int newTarget;

    for (auto x : arr){
        newTarget = targetSum - x;
        
        if (canSum(newTarget, arr, mp)){
            mp[targetSum] = true;
            return true;
        }
    }
    
    mp[targetSum] = false;
    return false;
}

int main(){
    unordered_map<int, bool> mp = {};
    vector<int> vec = {2, 3, 5};
    cout << canSum(8, vec, mp);
    return 0;
}
