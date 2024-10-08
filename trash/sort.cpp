#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
    vector<vector<string>> ans;
    unordered_map<string, vector<int>> map;
    vector<string> keys;

    void keyingIntoMap(string s, int i){
        sort(s.begin(), s.end());
        if(map.count(s) == 0){
            vector<int> val = {i};
            map[s] = val;
            keys.push_back(s);
        }else 
            map[s].push_back(i);
    }

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if(strs.size() <= 1){
            ans.push_back(strs);
            return ans;
        }
        int i = 0;
        for(string s: strs){
            keyingIntoMap(s, i);
            i++;
        }
        for(string key: keys){
            vector<string> pair;
            for(int i = 0; i < map[key].size(); i++)
                pair.push_back(strs[map[key][i]]);
            ans.push_back(pair);
        }
        return ans;  
    }
};


int main(){
    return 0;
}