//  Longest Consecutive Sequence
#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
using namespace std;


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxCount = 0;
        int count = 0;

        set<int> mySet;
        for(int i = 0; i < nums.size(); i++){
            mySet.insert(nums[i]);
        }

        int i = 0;
        for(int num : mySet){
            if(mySet.find(num-1) == mySet.end()){
                count = 1;
                int currentNum = num;
                while(mySet.find(currentNum + 1) != mySet.end()){
                    count++;
                    currentNum++;
                }
                maxCount = max(maxCount, count);
            }
        }
        return maxCount;
    }
};


int main(){
    Solution sol;
    // vector<int> nums = {200,4,200,1,3,2};
    vector<int> nums = {1,0,1,2,3};
    int result = sol.longestConsecutive(nums);
    cout << "Longest Consecutive Sequence Length: " << result << endl;
    return 0;
}
