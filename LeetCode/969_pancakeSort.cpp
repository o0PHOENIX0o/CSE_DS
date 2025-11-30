#include<iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    // int maxElement(vector<int> arr){
    //     int maxNum = INT_MIN;
    //     for(int i = 0; i< arr.size(); i++){
    //         maxNum = max(maxNum, arr[i]);
    //     }
    //     return maxNum;
    // }

    int getIndex(int target, const vector<int>& v) {
        auto it = find(v.begin(), v.end(), target);
        if (it != v.end())  return distance(v.begin(), it);
        return -1;
    }

    void reverse(vector<int>& arr, int k){
        int left = 0, right = k;
        while(left < right){
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }

    void printVector(const vector<int>& arr){
        for(int i = 0; i< arr.size(); i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    // vector<int> pancakeSort(vector<int>& arr) {
    //     int sortedIndex = arr.size() - 1;
    //     priority_queue<int> pq;
    //     vector<int> res;

    //     for(int num: arr) pq.push(num);

    //     while(!pq.empty() && sortedIndex >= 0){
    //         printVector(arr);
    //         int maxNum = pq.top();
    //         int maxIndex = getIndex(maxNum, arr);
    //         cout << "Max Num: " << maxNum << ", Max Index: " << maxIndex << ", Sorted Index: " << sortedIndex << endl;
    //         if(maxIndex == sortedIndex){
    //             sortedIndex--;
    //             pq.pop();
    //             continue;
    //         }

    //         if(maxIndex == 0) {
    //             reverse(arr, sortedIndex);
    //             res.push_back(sortedIndex + 1);
    //             sortedIndex--;
    //             pq.pop();
    //             continue;
    //         }else{
    //             reverse(arr, maxIndex);
    //             res.push_back(maxIndex + 1);
    //         }

    //     }

    //     return res;

    // }
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> res;
        int sortedIndex = arr.size() - 1;

        for(int maxNum = arr.size(); maxNum > 1; maxNum--){
            printVector(arr);
            int maxIndex = getIndex(maxNum, arr);
            cout << "Max Num: " << maxNum << ", Max Index: " << maxIndex << ", Sorted Index: " << sortedIndex << endl;
            
            if(maxIndex == maxNum-1) continue;

            if(maxIndex > 0){
                reverse(arr, maxIndex);
                res.push_back(maxIndex + 1);
            }

            reverse(arr, maxNum - 1);
            res.push_back(maxNum);

        }

        return res;

    }
};


int main(){
    Solution sol;
    vector<int> arr = {3,2,4,1};
    vector<int> res = sol.pancakeSort(arr);
    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<" ";
    }
    return 0;
}
