#include<bits/stdc++.h>

using namespace std;

bool canConstruct(string target, vector<string> list){
    vector<bool> result(target.length() + 1, false);
    result[0] = true;

    for (int i = 0; i <= target.length(); i++){
        if (result[target.length()]){
            return true;
        }

        if (result[i]){
            for (auto word : list){
                if (target.find(word) == i && (i + word.length() <= target.length())){
                    result[i + word.length()] = true; 
                }
            }
        }
    }

    return result[target.length()];
}

int main(){
    vector<string> list = {"ab", "abc", "de", "cd"};
    string temp = "abcdef";

    cout << canConstruct(temp, list);
    return 0;
}
