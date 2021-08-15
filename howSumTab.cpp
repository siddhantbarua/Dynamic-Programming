#include<bits/stdc++.h>

using namespace std;

vector<int> howSum(int target, const vector<int> &nums){
    vector<vector<int>> targetPossible(target + 1, vector<int>(1, INT_MIN));
    targetPossible[0] = {};

    vector<int> bad = {INT_MIN};

    for (int i = 0; i <= target; i++){
        if (targetPossible[i] != bad){
            for (auto x : nums){
                if(i + x <= target){
                    targetPossible[i + x] = targetPossible[i];
                    targetPossible[i + x].push_back(x);
                }
            }
        }
    }


    return targetPossible[target];
}

int main(){
    int target = 8;
    vector<int> nums = {3, 5, 6 , 2, 4};

    vector<int> result = howSum(target, nums);

    cout << result.size() << "\n";
    for (auto x : result){
        cout << x << " ";
    }
    return 0;
}
