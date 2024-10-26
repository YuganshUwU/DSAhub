/*    LeetCode link : https://leetcode.com/problems/height-of-binary-tree-after-subtree-removal-queries/
      Difficulty : Hard
*/

// Time Complexity : O(n + m)
// Space Complexity : O(N)  (vectors size -> O(4 * n ) to be more precise) + O(h) (stack memory)
  
#define INC()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    vector<int> level = vector<int>(100001);
    vector<int> height = vector<int>(100001);
    vector<int> maxHeightAt = vector<int>(100001);
    vector<int> secMaxHeightAt = vector<int>(100001);

    int findHeight(TreeNode* root, int l) {
        if (!root)
            return 0;

        level[root->val] = l;
        height[root->val] =
            max(findHeight(root->left, l + 1), findHeight(root->right, l + 1)) + 1;

        if (maxHeightAt[l] < height[root->val]) {
            secMaxHeightAt[l] = maxHeightAt[l];
            maxHeightAt[l] = height[root->val];
        } else if (secMaxHeightAt[l] < height[root->val])
            secMaxHeightAt[l] = height[root->val];

        return height[root->val];
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        INC();

        findHeight(root, 0);
        vector<int> result;

        for (int& currNode : queries) {
            int l = level[currNode];
            int curr = l + (height[currNode] == maxHeightAt[l] ? secMaxHeightAt[l] : maxHeightAt[l]) - 1;
            result.push_back(curr);
        }

        return result;
    }
};
