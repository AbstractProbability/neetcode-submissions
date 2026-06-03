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
    ListNode* reverseList(ListNode* head) {
        if (!head) { return NULL; }
        
        ListNode *ret = head;
        ListNode *prev = NULL;
        while (ret) {
            ListNode *temp = ret->next;
            ret->next = prev;
            prev = ret;
            ret = temp;
        }
        return prev;
    }
};
