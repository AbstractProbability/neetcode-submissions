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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int total = 0;
        ListNode *temp = head;
        while (temp) {
            temp = temp->next;
            total++;
        }
        
        ListNode *curr = head, *prev = NULL;
        int remaining = total-n;
        while (remaining) {
            prev = curr;
            curr = curr->next;
            remaining--;
        }
        
        if (!prev) {
            head = head->next;
        } else {
            prev->next = curr->next;
        }

        // free(curr);
        return head;
    }
};
