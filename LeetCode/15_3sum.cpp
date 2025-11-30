


#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for(int i = 0; i<nums.size(); i++){
            if(nums[i] > 0) break;

            if(i>0 && nums[i]==nums[i-1]) continue;
            int left = i+1, right = nums.size() - 1;

            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                if(sum > 0) right--;
                else if(sum < 0) left++;
                else {
                    cout << "Found triplet: " << nums[i] << ", " << nums[left] << ", " << nums[right] << endl;
                    res.push_back({nums[i], nums[left], nums[right]});

                    right--;
                    left++;
                    while(left < right && nums[right+1]==nums[right]) right--;
                    while(left < right && nums[left-1]==nums[left]) left++;
                }
            }
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {2,-3,0,-2,-5,-5,-4,1,2,-2,2,0,2,-4,5,5,-10};
    vector<vector<int>> result = sol.threeSum(nums);
    for(const auto& triplet : result){
        cout << "[";
        for(int num : triplet){
            cout << num << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}