#include<bits/stdc++.h>

using namespace std;

int countConstruct(string target, const vector<string>& list, unordered_map<string, int>& map){

    if (map.find(target) != map.end()){
        return map[target];
    }

    if (target == ""){
        return 1;
    }

    string temp;
    int ways = 0;

    for (auto s : list){

        if (target.find(s) == 0){
            temp = target.substr(s.length()); 
            ways += countConstruct(temp, list, map);

        }
    }


    map[target] = ways;
    return ways;
}

int main(){

    vector<string> list = {"a", "p", "ent", "enter", "ot", "o", "t"};
    unordered_map<string, int> map = {};

    cout << countConstruct("enterapotentpot", list, map);
    return 0;
}
