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
    ListNode* deleteDuplicates(ListNode* head) {
        // ListNode *temp = head;
        // if(!head) return NULL;
        // while(temp->next){
        //     if(temp->val == temp->next->val){
        //         ListNode *p = temp->next;
        //         temp->next = p->next;
        //         delete p;
        //     }
        //     else{
        //         temp = temp->next;
        //     }
        // }
        // return head;
        if(!head || !head->next) return head;
        head->next = deleteDuplicates(head->next);
        
        if(head->val == head->next->val){
            ListNode *p = head->next;
            head->next = p->next;
            delete p;
        }
        return head;
    }
};