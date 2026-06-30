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
    ListNode *reverse(ListNode *head)
    {
        ListNode *prev = NULL, *temp = head, *temp2;
        while (temp) {
            temp2 = temp->next;
            temp->next = prev;
            prev = temp;
            temp = temp2;
        }
        return prev;
    }
    void merge(ListNode *first, ListNode *second)
    {
        ListNode *temp;
        while (first && second) {
            temp = first->next;
            first->next = second;
            first = temp;

            temp = second->next;
            second->next = first;
            second = temp;
        }
    }
public:
    void reorderList(ListNode* head) {
        ListNode *head2 = head;
        int total = 0;
        while (head2) {
            head2 = head2->next;
            total++;
        }
        int half = total/2 + total%2;
        head2 = head;
        ListNode *prev; 
        while (half) {
            prev = head2;
            head2 = head2->next;
            half--;
        }
        prev->next = NULL;
        head2 = reverse(head2);
        merge(head, head2);
    }
};
