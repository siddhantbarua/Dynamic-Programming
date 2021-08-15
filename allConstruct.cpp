#include<bits/stdc++.h>

using namespace std;

vector<vector<string>> allConstruct(string target, const vector<string>& list, unordered_map<string, vector<vector<string>>>& map){

    if (map.find(target) != map.end()){
        return map[target];
    }

    if (target == ""){
        return {{}};
    }

    string temp;
    vector<vector<string>> ways;
    vector<vector<string>> result;

    for (auto word : list){

        if (target.find(word) == 0){
            temp = target.substr(word.length()); 
            ways = allConstruct(temp, list, map);

            for (auto &vec : ways){
                vec.insert(vec.begin(), word);
                result.push_back(vec);
            }
        }
    }


    map[target] = result;
    return result;
}

int main(){

    vector<string> list = {"a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa"};
    unordered_map<string, vector<vector<string>>> map = {};

    auto result = allConstruct("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", list, map);

    for (auto vec : result){
        for (auto str : vec){
            cout << str << " ";
        }
        cout << "\n";
    }
    return 0;
}
