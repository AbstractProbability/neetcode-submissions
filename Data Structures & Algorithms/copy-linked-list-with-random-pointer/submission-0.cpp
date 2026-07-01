/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        vector<Node *> idx_to_add;
        unordered_map<Node *, int> add_to_idx;
        Node *temp = head, *new_head = NULL, *new_temp;
        
        while (temp) {
            if (!new_head) {
                new_head = new Node(head->val);
                new_temp = new_head;
            } else {
                new_temp->next = new Node(temp->val);
                new_temp = new_temp->next;
            }

            // new linked list's nodes indexed
            idx_to_add.push_back(new_temp);

            // original linked list's hashmap
            add_to_idx[temp] = idx_to_add.size()-1;

            temp = temp->next;
        }

        temp = head, new_temp = new_head;
        while (temp) {
            if (temp->random == NULL) {
                new_temp->random = NULL;
            } else {
                int rand_idx = add_to_idx[temp->random];
                new_temp->random = idx_to_add[rand_idx];
            }
            
            temp = temp->next;
            new_temp = new_temp->next;
        }

        return new_head;
    }
};
