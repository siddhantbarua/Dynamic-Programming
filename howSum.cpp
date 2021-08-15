#include<bits/stdc++.h>

using namespace std;

vector<int> howSum(int targetSum, vector<int>& arr, unordered_map<int, vector<int>>& mp){

    if (mp.find(targetSum) != mp.end()){
        return mp[targetSum];
    }

    if (targetSum == 0){
        return {};
    }

    if (targetSum < 0){
        return {INT_MIN};
    }
    
    int newTarget;

    for (auto x : arr){
        newTarget = targetSum - x;
        
        vector<int> temp = howSum(newTarget, arr, mp);
        vector<int> bad = {INT_MIN};

        if (temp != bad){
            temp.push_back(x);
            mp[targetSum] = temp;
            return mp[targetSum];
        }
    }

    mp[targetSum] = {INT_MIN};
    return mp[targetSum];
}

int main(){
    unordered_map<int, vector<int>> mp = {};
    vector<int> vec = {7, 14};
    vector<int> result = howSum(300, vec, mp);

    for (int i = 0; i < result.size(); i++){
        cout << result[i];
    }
    return 0;
}
