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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL){
            return l2;
        }
        if(l2 == NULL){
            return l1;
        }
        ListNode *temp = new ListNode(-101);
        ListNode *head = temp;
        while(l1 and l2){
            if(l1-> val < l2->val){
                ListNode *newNode = new ListNode(l1->val);
                temp->next = newNode;
                temp = temp->next;
                l1 = l1->next;
            }
            else{
                ListNode *newNode = new ListNode(l2->val);
                temp->next = newNode;
                temp = temp->next;
                l2 = l2->next;
            }
        }
        while(l1){
            ListNode *newNode = new ListNode(l1->val);
            temp->next = newNode;
            temp = temp->next;
            l1 = l1->next;
        }
        while(l2){
            ListNode *newNode = new ListNode(l2->val);
            temp->next = newNode;
            temp = temp->next;
            l2 = l2->next;
        }
        return head->next;
    }
};