#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    map<int, string> numberMap = {
        {2, "abc"},
        {3, "def"},
        {4, "ghi"},
        {5, "jkl"},
        {6, "mno"},
        {7, "pqrs"},
        {8, "tuv"},
        {9, "wxyz"}
    };

 vector<string> res;
    void recursive(string digits, int i, string str){
        if(digits.length() == str.length()){
            res.push_back(str);
            return;
        }

        for(char c: numberMap[digits[i]-'0']){
            recursive(digits,  i+1, str+c);
        }
    }

    vector<string> letterCombinations(string digits) {
        recursive(digits, 0, "");
        return res;
    }
};

int main(){
    Solution s;
    string digits = "23";
    vector<string> ans = s.letterCombinations(digits);
    for(string str: ans){
        cout<<str<<" ";
    }
    return 0;
}