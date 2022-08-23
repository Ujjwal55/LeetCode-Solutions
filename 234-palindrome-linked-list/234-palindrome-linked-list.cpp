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
    bool isPalindrome(ListNode* head) {
        
        ListNode *slow = head, *fast = head;
        ListNode *prev;
        while(fast && fast->next && fast->next->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *a = slow->next;
        ListNode *curr = NULL;
        while(a){
            ListNode *temp = a->next;
            a->next = curr;
            curr = a;
            a = temp;
        }
        slow->next = curr;
        slow = head;
        while(curr){
            if(curr->val != slow->val) return false;
            curr = curr->next;
            slow = slow->next;
        }
        return true;
    }
};