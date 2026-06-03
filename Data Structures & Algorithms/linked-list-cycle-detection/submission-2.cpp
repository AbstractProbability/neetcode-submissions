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

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (!head || !head->next || !head->next->next) { return false; }

        ListNode *fast = head->next->next;
        ListNode *slow = head;
        while (fast && slow) {
            if (fast == slow) {
                return true;
            }
            slow = slow->next;
            if (fast->next) { fast = fast->next->next; }
            else { fast = fast->next; }
        }
        return false;
    }
};
