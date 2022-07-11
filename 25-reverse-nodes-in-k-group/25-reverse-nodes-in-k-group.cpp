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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *temp = head;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        int cnt = 0;
        while(temp){
            cnt++;
            temp = temp->next;
        }
        int n = cnt/k;
        temp = head;
        cnt = 0;
        ListNode *curr = temp;
        ListNode *prev = dummy;
        ListNode *p = dummy;
        while(cnt < n){
            int numberofNodes = 0;
            ListNode *a = curr;
            while(numberofNodes < k){
                temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
                numberofNodes++;
            }
            a->next = temp;
            p->next = prev;
            p = a;
            cnt++;
        }
        return dummy->next;
    }
};