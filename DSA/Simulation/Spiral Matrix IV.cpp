/*  Leetcode Link : https://leetcode.com/problems/spiral-matrix-iv/
    Difficulty : Medium
*/

// Time Complexity : O(min(size, O(m*n))) where, size = size of the linked list
// Space Complexity : O(m*n)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        inc();

        vector<vector<int>> result(m, vector<int>(n, -1));
        int left = 0, top = 0;
        int right = n - 1, bottom = m - 1;

        while (head) {
            while (top <= bottom && left <= right) {
                for (int i = left; i <= right; i++) {
                    if (!head)
                        break;

                    result[top][i] = head->val;
                    head = head->next;
                }

                top++;

                for (int i = top; i <= bottom; i++) {
                    if (!head)
                        break;

                    result[i][right] = head->val;
                    head = head->next;
                }

                right--;

                if (top <= bottom) {
                    for (int i = right; i >= left; i--) {
                        if (!head)
                            break;

                        result[bottom][i] = head->val;
                        head = head->next;
                    }

                    bottom--;
                }

                if (left <= bottom) {
                    for (int i = bottom; i >= top; i--) {
                        if (!head)
                            break;

                        result[i][left] = head->val;
                        head = head->next;
                    }

                    left++;
                }
            }
        }

        return result;
    }
};
