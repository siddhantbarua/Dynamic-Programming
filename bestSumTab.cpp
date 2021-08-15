#include<bits/stdc++.h>

using namespace std;

vector<int> bestSum(int target, const vector<int> &nums){
    vector<vector<int>> result(target + 1, vector<int>(1, INT_MIN));
    result[0] = {};

    vector<int> bad = {INT_MIN};

    for (int i = 0; i <= target; i++){
        if (result[i] != bad){
            for (auto x : nums){
                if(i + x <= target){
                    if (result[i + x] == bad || result[i + x].size() > result[i].size() + 1){
                        result[i + x] = result[i];
                        result[i + x].push_back(x);
                    }
                }
            }
        }
    }


    return result[target];
}

int main(){
    int target = 8;
    vector<int> nums = {3, 5, 6 , 2, 4};

    vector<int> result = bestSum(target, nums);

    cout << result.size() << "\n";
    for (auto x : result){
        cout << x << " ";
    }
    return 0;
}
