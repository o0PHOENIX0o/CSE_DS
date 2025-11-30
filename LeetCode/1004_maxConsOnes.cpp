#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int longestOnes(vector<int> &nums, int k) {
        int maxCount = 0;
        int Zcount = 0;
        int left = 0;

        for(int right =0; right < nums.size(); right++){
            if(nums[right] == 0) Zcount++;
            while(Zcount > k ){
                if(nums[left] == 0) Zcount--;
                left++;
            }
            maxCount = max(maxCount, right - left +1); 
        }
        return maxCount;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,1,1, 0,0,0,1,1,1,1,0};
    // vector<int> nums = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    int k = 2;
    int result = sol.longestOnes(nums, k);
    cout << "Max Consecutive Ones with K flips: " << result << endl;
    return 0;
}