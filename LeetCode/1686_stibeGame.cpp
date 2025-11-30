#include<iostream>
#include<queue>
#include<unordered_map>
#include<vector>



using namespace std;
class Solution {
public:
    struct stone{
        int index;
        int value;
    };
    struct comp{
        bool operator()(stone &a, stone &b){
            return a.value < b.value;
        }
    };

    void printPq(priority_queue<stone, vector<stone>, comp> pq){
        while(!pq.empty()){
            pq.pop();
        }
    }

    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        priority_queue<stone, vector<stone>, comp> stones;

        for(int i=0;i < n; i++){
            stones.push({i, aliceValues[i] + bobValues[i]});
        }

        printPq(stones);

        int alicePoints = 0, bobPoints =0;
        for(int i=0;i < n; i++){
            int index = stones.top().index;
            cout<<"Chosen Stone Index: "<<index<< " value: ";
            if(i % 2 == 0){
                cout<<aliceValues[index]<<endl;
                alicePoints += aliceValues[i];
            } 
            else{
                cout<<bobValues[index]<<endl;
                bobPoints += bobValues[i];
            }
            stones.pop();
        }

        cout<<"Alice Points: "<<alicePoints<<endl;
        cout<<"Bob Points: "<<bobPoints<<endl;

        if(alicePoints > bobPoints) return 1;
        if(bobPoints > alicePoints) return -1;
        return 0;
    }
};




int main(){
    Solution sol;
    vector<int> alice = {1,3};
    vector<int> bob = {2,1};
    cout<<sol.stoneGameVI(alice, bob)<<endl;
    return 0;
}