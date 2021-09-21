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
        ListNode *temp1 = l1, *temp2 = l2;
        ListNode *q1 = NULL, *q2 = NULL;
        ListNode *r1 = NULL, *r2 = NULL;
        int rem=0;
        while(temp1){
            r1 = q1;
            q1 = temp1;
            temp1 = temp1->next;
            q1->next = r1;
        }
        l1 = q1;
        temp1 = l1;
        while(temp2){
            r2 = q2;
            q2 = temp2;
            temp2 = temp2->next;
            q2->next = r2;
        }
        l2 = q2;
        temp2 = l2;
        ListNode *h = NULL, *t = NULL;
        while(temp1 && temp2){
            ListNode *b = new ListNode(temp1->val+temp2->val+rem);
            if(h == NULL){
                h = b;
                t = b;
            }
            else{
                t->next = b;
                t = t->next;
            }
            rem = t->val/10;
            t->val = t->val%10;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        while(temp1!=NULL){
            ListNode *b = new ListNode(temp1->val+rem);
            t->next = b;
            t = t->next;
            rem = t->val/10;
            t->val = t->val%10;
            temp1 = temp1->next;
        }
        while(temp2!=NULL){
            ListNode *b = new ListNode(temp2->val+rem);
            t->next = b;
            t = t->next;
            rem = t->val/10;
            t->val = t->val%10;
            temp2 = temp2->next;
        }
        if(rem){
            ListNode *b = new ListNode(rem);
            t->next = b;
            t = t->next;
        }
        q1 = NULL, r1 = NULL;
        temp1 = h;
        while(temp1){
            r1 = q1;
            q1 = temp1;
            temp1 = temp1->next;
            q1->next = r1;
        }
        h = q1;
        return h;
    }
};