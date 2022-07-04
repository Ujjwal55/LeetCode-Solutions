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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *d = new ListNode(-1);
        d->next = head;
        ListNode *curr = head, *prev = d;
        while(curr){
            if(curr->next && curr->val > curr->next->val){
                while(prev->next && prev->next->val < curr->next->val){
                    prev = prev->next;
                }
                ListNode *temp = prev->next;
                prev->next = curr->next;
                curr->next = curr->next->next;
                prev->next->next = temp;
                prev = d;
            }
            else{
                curr = curr->next;
            }
        }
        return d->next;
    }
};