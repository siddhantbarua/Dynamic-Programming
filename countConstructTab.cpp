#include<bits/stdc++.h>

using namespace std;

// Array entry at i + 1, is number of ways you can generate string from 0 to i
int countConstruct(string target, vector<string> list){
    vector<int> result(target.length() + 1, 0);
    result[0] = 1;

    for (int i = 0; i <= target.length(); i++){
        
        if (result[i]){
            for (auto word : list){
                if (target.find(word) == i && (i + word.length() <= target.length())){
                    result[i + word.length()] += result[i]; 
                }
            }
        }
    }

    return result[target.length()];
}

int main(){
    vector<string> list = {"ab", "abc", "def", "cd", "ef"};
    string temp = "abcdef";

    cout << countConstruct(temp, list);
    return 0;
}
