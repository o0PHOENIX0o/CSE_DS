#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include <cstdint>
#include <cmath>

using namespace std;



string getKey(const string& str) {
    int counts[26] = {0};
    for(char c : str){
        counts[c - 'a']++;
    }

    string key;
    for(int i = 0; i < 26; i++){
        if(counts[i] > 0){
            key += string(counts[i], 'a' + i);
        }
    }
    return key;
}

class Solution {
public:
    unordered_map<string, vector<string>> mp;
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        for(const string& str : strs){
            string keyVal = getKey(str);
            mp[keyVal].push_back(str);
        }

        vector<vector<string>> res;
        for(auto& pair : mp){
            cout<<"Key: " << pair.first << " -> ";
            for(const string& s : pair.second){
                cout << s << " ";
            }
            cout << endl;
            res.push_back(pair.second);
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<string> strs = {"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab"};
    vector<vector<string>> result = sol.groupAnagrams(strs);
    for(const auto& group : result){
        cout << "[";
        for(const auto& str : group){
            cout << str << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}