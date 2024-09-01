/*  LeetCode link : https://leetcode.com/problems/most-frequent-subtree-sum/
    Difficulty : Medium
*/

// Time Complexity : O(n)
// Space Complexity : O(n) 

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    int calculatingSum(TreeNode* root, unordered_map<int, int>& mp) {
        if (!root)
            return 0;

        int leftSum = calculatingSum(root->left, mp);
        int rightSum = calculatingSum(root->right, mp);
        mp[root->val + leftSum + rightSum]++;

        return root->val + leftSum + rightSum;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        inc();

        unordered_map<int, int> mp;
        calculatingSum(root, mp);

        priority_queue<pair<int, int>> pq;

        for (auto& it : mp) {
            pq.push({it.second, it.first});
        }

        vector<int> result;
        int max = pq.top().first;

        while (!pq.empty() && pq.top().first == max) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};
