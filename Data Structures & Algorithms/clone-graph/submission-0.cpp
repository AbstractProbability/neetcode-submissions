/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) { return NULL; }
        map<Node *, Node *> mp;
        queue<Node *> q1, q2;

        q1.push(node);
        Node *ret = new Node(node->val);
        q2.push(ret);
        mp[node] = ret;
        while (!q1.empty()) {
            Node *front1 = q1.front();
            Node *front2 = q2.front();
            q1.pop();
            q2.pop();
            for (auto v: front1->neighbors){ 
                if (!mp[v]) {
                    q1.push(v);
                    Node *newnode = new Node(v->val);
                    q2.push(newnode);
                    mp[v] = newnode;
                }
                // mp[v]->neighbors.push_back(front2);
                front2->neighbors.push_back(mp[v]);
            }
        }

        return ret;
    }
};
