#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.length();
        int n2 = num2.length();
        
        vector<int> ans(n1 + n2-1, 0);

        for(int i = n1-1; i>= 0; i--){
            for(int j = n2-1; j>= 0; j--){
                ans[i+j] += (num1[i] - '0') * (num2[j] - '0');
            }
        }
        
        for(int i : ans) {
            cout << i << " ";
        }
        cout<<endl;

        string res(n1 + n2, '0');
        int carry = 0;
        int i;
        for(i = ans.size() - 1; i >= 0; i--) {
            if (ans[i] == 0 && carry == 0) {
                cout<<"skipping index: " << i << " value: " << ans[i] << endl;
                continue;
            };
            int num =  ans[i] + carry;
            carry = num / 10;
            num = num % 10;
            cout << "num: " << num << " carry: " << carry << endl;
            res[i+1] = (num + '0');
        }

        if (carry > 0) res[0] = (carry + '0');
        else res = res.substr(1);
        
        return res;
    }
};

int main() {
    Solution sol;
    string num1 = "408";
    string num2 = "5";
    string result = sol.multiply(num1, num2);
    cout << "Result: " << result << endl;
    return 0;
}
