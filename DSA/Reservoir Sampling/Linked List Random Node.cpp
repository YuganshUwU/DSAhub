/*  Leetcode link : https://leetcode.com/problems/linked-list-random-node/
    Difficulty : Medium
*/

// Time Complexity : O(n)
// Space Complexity : O(n)

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
    ListNode* temp = NULL;
    Solution(ListNode* head) : temp(head) { 
        inc(); 
    }

    int getRandom() {
        
        ListNode* curr = temp;
        ListNode* result = NULL;
        int n = 0;

        while (curr) {
            n++;

            int randomVal = rand() % n;
            if (randomVal == n - 1)
                result = curr;

            curr = curr->next;
        }

        return result->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
