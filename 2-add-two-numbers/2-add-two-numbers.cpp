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
    ListNode *recurse(ListNode *l1, ListNode *l2, int carry){
        if(!l1 && !l2){
            if(carry) return new ListNode(1);
            return NULL;
        }
        int sum = 0;
        if(l1){
            sum += l1->val;
            l1 = l1->next;
        }
        if(l2){
            sum += l2->val;
            l2 = l2->next;
        }
        sum += carry;
        ListNode *s = new ListNode(sum%10);
        s->next = recurse(l1, l2, sum/10);
        return s;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // ListNode *s = new ListNode(-1);
        // ListNode *temp = s;
        // int carry = 0;
        // int sum;
        // while(l1 || l2 || carry){
        //     sum = 0;
        //     if(l1){
        //         sum += l1->val;
        //         l1 = l1->next;
        //     }
        //     if(l2){
        //         sum += l2->val;
        //         l2 = l2->next;
        //     }
        //     sum += carry;
        //     carry = sum/10;
        //     ListNode *a = new ListNode(sum%10);
        //     s->next = a;
        //     s = a;
        // }
        // return temp->next;
        return recurse(l1, l2, 0);
    }
};