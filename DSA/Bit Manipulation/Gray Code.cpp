/*  LeetCode link : https://leetcode.com/problems/gray-code/
    Difficulty : Medium
*/

// Approach 1 - Recursive Backtracking
// Time Complexity : O(2^n)
// Space Complexity : O(2^n) excluding stack memory

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    vector<string> finding(int n) {
        if (n == 1)
            return {"0", "1"};

        vector<string> temp = finding(n - 1);
        vector<string> curr;

        for (int i = 0; i < temp.size(); i++)
            curr.push_back("0" + temp[i]);

        for (int i = temp.size() - 1; i >= 0; i--)
            curr.push_back("1" + temp[i]);

        return curr;
    }

    vector<int> grayCode(int n) {
        inc();

        vector<string> grayString = finding(n);
        vector<int> result;

        for (string& st : grayString) {
            int curr = stoi(st, 0, 2);
            result.push_back(curr);
        }

        return result;
    }
};

--------------------------------------------------------------------------------------------------------------

// Approach 2 - Bit Manipulation
// Complexities : Same but no memory stack involved
  
#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:

    vector<int> grayCode(int n) {
        inc();

        vector<int> result;
        int length = 1 << n;

        for(int i = 0; i < length; i++){
            int num = i ^ (i >> 1);
            result.push_back(num);
        }

        return result;
    }
};
