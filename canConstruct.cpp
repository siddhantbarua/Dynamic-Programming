#include<bits/stdc++.h>

using namespace std;

bool canConstruct(string target, const vector<string>& list, unordered_map<string, bool>& map){

    if (map.find(target) != map.end()){
        return map[target];
    }

    if (target == ""){
        return true;
    }

    string temp;

    for (auto s : list){

        if (target.find(s) == 0){
            temp = target.substr(s.length());   // from s.length() to end

            if (canConstruct(temp, list, map)){
                map[target] = true;
                return true;
            }

        }
    }


    map[target] = false;
    return false;
}

int main(){

    vector<string> list = {"e", "ee", "eee", "eeee", "eeeee", "eeeeee", "eeeeeeee"};
    unordered_map<string, bool> map = {};

    cout << canConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee", list, map);
    return 0;
}
