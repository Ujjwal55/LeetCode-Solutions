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
    ListNode *changeList(ListNode *head){
        if(!head->next || !head->next->next) return head;
        ListNode *last = changeList(head->next->next);
        ListNode *second = head->next;
        head->next = second->next;
        second->next = last->next;
        last->next = second;
        return last;
    }
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL) return head;
        changeList(head);
        return head;
    }
};