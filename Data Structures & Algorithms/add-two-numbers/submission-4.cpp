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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0, carry = 0;
        ListNode *head = NULL, *temp = head;
        ListNode *temp1 = l1, *temp2 = l2;
        
        while (temp1 || temp2) {
            int val1 = temp1 ? temp1->val : 0;
            int val2 = temp2 ? temp2->val : 0;
            sum = val1 + val2 + carry;
            carry = sum/10;
            sum %= 10;

            if (!head) {
                head = new ListNode(sum);
                temp = head;
            } else {
                temp->next = new ListNode(sum);
                temp = temp->next;
            }

            temp1 = temp1 ? temp1->next : temp1;
            temp2 = temp2 ? temp2->next : temp2;
        }

        if (carry) {
            temp->next = new ListNode(carry);
            temp = temp->next;
        }

        return head;
    }
};
