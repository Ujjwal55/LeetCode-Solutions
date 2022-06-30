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
    ListNode* reverseList(ListNode* head) {
        // ListNode *curr = NULL;
        // while(head){
        //     ListNode *temp = head->next;
        //     head->next = curr;
        //     curr = head;
        //     head = temp;
        // }
        // return curr;
        if(!head || !head->next) return head;
        ListNode *temp = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return temp;
    }
};