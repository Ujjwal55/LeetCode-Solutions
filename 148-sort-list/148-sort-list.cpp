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
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *slow = head, *fast = head;
        ListNode *prev = NULL;
        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        ListNode *left = sortList(head);
        ListNode *right = sortList(slow);
        return merge(left, right);
    }
    ListNode *merge(ListNode *left, ListNode *right){
        ListNode *temp;
        ListNode *temp1 = left, *temp2 = right;
        while(left && right){
            if(left->val <= right->val){
                while(left && left->val <= right->val){
                    temp = left;
                    left = left->next;
                }
                temp->next = right;
            }
            else{
                while(right && right->val < left->val){
                    temp = right;
                    right = right->next;
                }
                temp->next = left;
            }
        }
        return temp1->val <= temp2->val ? temp1 : temp2;
    }
};