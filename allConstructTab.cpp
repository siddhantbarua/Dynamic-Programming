#include<bits/stdc++.h>

using namespace std;

// Array entry at i + 1, is number of ways you can generate string from 0 to i
vector<vector<string>> allConstruct(string target, vector<string> list){
    vector<vector<string>> temp = {};
    vector<vector<vector<string>>> result(target.length() + 1, temp);
    result[0] = {{}};

    for (int i = 0; i <= target.length(); i++){
        
        if (result[i].size()){
            for (auto word : list){
                if (target.find(word) == i && (i + word.length() <= target.length())){
                    for (auto y : result[i]){
                        y.push_back(word);
                        result[i + word.length()].push_back(y);
                    }
                }
            }
        }
    }

    return result[target.length()];
}

int main(){
    vector<string> list = {"ab", "abc", "def", "cd", "ef"};
    string temp = "abcdef";

    vector<vector<string>> result = allConstruct(temp, list);

    for (auto x : result){
        for (auto y : x){
            cout << y << " ";
        }
        cout << "\n";
    }
    return 0;
}
