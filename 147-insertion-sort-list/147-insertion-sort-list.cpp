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
    ListNode *recurse(ListNode *curr){
        if(!curr) return curr;
        curr->next = recurse(curr->next);
        if(!curr->next) return curr;
        if(curr->val <= curr->next->val) return curr;
        ListNode *a = curr, *b = curr->next;
        while(a->next && a->next->val < curr->val){
            a = a->next;
        }
        curr->next = a->next;
        a->next = curr;
        return b;
    }
    ListNode* insertionSortList(ListNode* head) {
        // ListNode *d = new ListNode(-1);
        // d->next = head;
        // ListNode *curr = head, *prev = d;
        // while(curr){
        //     if(curr->next && curr->val > curr->next->val){
        //         while(prev->next && prev->next->val < curr->next->val){
        //             prev = prev->next;
        //         }
        //         ListNode *temp = prev->next;
        //         prev->next = curr->next;
        //         curr->next = curr->next->next;
        //         prev->next->next = temp;
        //         prev = d;
        //     }
        //     else{
        //         curr = curr->next;
        //     }
        // }
        // return d->next;
        return recurse(head);
    }
};