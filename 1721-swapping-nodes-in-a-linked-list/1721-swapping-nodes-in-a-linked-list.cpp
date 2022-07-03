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
    ListNode* swapNodes(ListNode* head, int k) {
        int cnt = 0;
        ListNode *temp = head;
        while(temp){
            cnt++;
            temp = temp->next;
        }
        int m = cnt-k+1;
        int i = 1, j = 1;
        ListNode *a = head, *b = head, *c = NULL, *d = NULL;
        while(i < k){
            a = a->next;
            i++;
        }
        while(j < m){
            b = b->next;
            j++;
        }
        swap(a->val, b->val);
        return head;
    }
};