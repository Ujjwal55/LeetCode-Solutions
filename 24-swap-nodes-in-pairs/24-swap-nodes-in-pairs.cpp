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
    ListNode* swapPairs(ListNode* head) {
        // ListNode *d = new ListNode(-1);
        // d->next = head;
        // ListNode *curr = d;
        // ListNode *a = head;
        // while(a && a->next){
        //     ListNode *temp = a->next->next;
        //     curr->next = a->next;
        //     a->next = a->next->next;
        //     curr->next->next = a;
        //     curr = curr->next->next;
        //     a = a->next;
        // }
        // return d->next;
        if(!head || !head->next){
            return head;
        }
        ListNode *temp = head->next;
        head->next = swapPairs(head->next->next);
        temp->next = head;
        return temp;
    }
};