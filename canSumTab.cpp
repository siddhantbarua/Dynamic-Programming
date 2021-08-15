#include<bits/stdc++.h>

using namespace std;

bool canSum(int target, const vector<int> &nums){
    vector<bool> targetPossible(target + 1, false);
    targetPossible[0] = true;       // 0 always possible

    for (int i = 0; i <= target; i++){
        if (targetPossible[i]){
            for (auto x : nums){
                if(i + x <= target){
                    targetPossible[i + x] = true;
                }
            }
        }
    }


    return targetPossible[target];
}

int main(){
    int target = 300;
    vector<int> nums = {7, 100};

    cout << canSum(target, nums);
    return 0;
}
