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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head || !head->next) return NULL;
        ListNode *a = new ListNode(-1);
        a->next = head;
        ListNode *prev = a;
        ListNode *curr = head;
        int i = 1;
        ListNode *temp = head;
        head = a;
        while(temp){
            if(i > n){
                prev = curr;
                curr = curr->next;
            }
            i++;
            temp = temp->next;
        }
        ListNode *p = prev->next;
        prev->next = prev->next->next;
        delete p;
        return head->next;
    }
};