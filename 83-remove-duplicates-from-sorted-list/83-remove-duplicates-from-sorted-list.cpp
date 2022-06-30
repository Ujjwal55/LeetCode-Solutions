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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *temp = new ListNode(-101);
        ListNode *temp1 = temp;
        int v = -101;
        while(head){
            if(v != head->val){
                temp->next = new ListNode(head->val);
                v = head->val;
                temp = temp->next;
            }
            head = head->next;
        }
        return temp1->next;
    }
};