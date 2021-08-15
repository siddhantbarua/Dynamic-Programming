#include<bits/stdc++.h>

using namespace std;

/*int gridTraveller(pair<int, int> coord){
    if (coord == make_pair(1, 1)){
        return 1;
    }
    if (coord.first == 0 || coord.second == 0){
        return 0;
    }

    return gridTraveller({coord.first - 1, coord.second}) + gridTraveller({coord.first, coord.second - 1});
}*/
struct hashPair{
    template <class T1, class T2> size_t operator()(const pair<T1, T2> &p) const{
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

int gridTraveller(pair<int, int> coord, unordered_map<pair<int, int>, long long int, hashPair>& mp){
    if (coord == make_pair(1, 1)){
        return 1;
    }
    if (coord.first == 0 || coord.second == 0){
        return 0;
    }

    if (mp.find(coord) != mp.end()){
        return mp[coord];
    }

    mp[coord] = gridTraveller({coord.first - 1, coord.second}, mp) + gridTraveller({coord.first, coord.second - 1}, mp);
    return mp[coord];
}

int main(){
    unordered_map<pair<int, int>, long long int, hashPair> mp = {}; 
    cout << gridTraveller({18, 18}, mp);
    return 0;
}
