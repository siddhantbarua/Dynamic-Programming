#include<bits/stdc++.h>

using namespace std;

vector<int> bestSum(int targetSum, vector<int>& arr, unordered_map<int, vector<int>>& mp){

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
    vector<int> shortest = {INT_MIN};

    for (auto x : arr){
        newTarget = targetSum - x;
        
        vector<int> temp = bestSum(newTarget, arr, mp);
        vector<int> bad = {INT_MIN};

        if (temp != bad){
            temp.push_back(x);

            if (shortest == bad || shortest.size() > temp.size()){
                shortest = temp;
            }

        }
    }

    mp[targetSum] = shortest;
    return shortest;
}

int main(){
    unordered_map<int, vector<int>> mp = {};
    vector<int> vec = {1, 2, 5, 25};
    vector<int> result = bestSum(100, vec, mp);

    for (int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    return 0;
}
