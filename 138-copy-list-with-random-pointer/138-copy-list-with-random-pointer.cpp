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
        // unordered_map<Node *, Node *> m;
        // Node *curr = head;
        // while(curr){
        //     Node *temp = new Node(curr->val);
        //     m[curr] = temp;
        //     curr = curr->next;
        // }
        // curr = head;
        // while(curr){
        //     m[curr]->next = m[curr->next];
        //     m[curr]->random = m[curr->random];
        //     curr = curr->next;
        // }
        // return m[head];
        if(!head) return head;
        Node *temp = head;
        while(temp){
            Node *curr = new Node(temp->val);
            curr->next = temp->next;
            temp->next = curr;
            temp = temp->next->next;
        }
        temp = head;
        while(temp){
            if(temp->random){
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next;
        }
        Node *clone = head->next , *temp1 = head->next;
        temp = head;
        while(temp){
            temp->next = temp1->next;
            if(temp1->next){
                temp1->next = temp1->next->next;
            }
            temp = temp->next;
            temp1 = temp1->next;
        }
        return clone;
    }
};