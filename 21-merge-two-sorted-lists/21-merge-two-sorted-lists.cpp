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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // if(!l1) return l2;
        // if(!l2) return l1;
        // ListNode *temp1 = l1, *temp2 = l2;
        // ListNode *a = NULL;
        // ListNode *prev = NULL;
        // while(l1 && l2){
        //     if(l1->val <= l2->val){
        //         while(l1 && l1->val <= l2->val){
        //             prev = l1;
        //             l1 = l1->next;
        //         }
        //         prev->next = l2;
        //     }
        //     else{
        //         while(l2 && l2->val < l1->val){
        //             prev = l2;
        //             l2 = l2->next;
        //         }
        //         prev->next = l1;
        //     }
        // }
        // if(temp1->val <= temp2->val) return temp1;
        // else return temp2;
        if(!l1) return l2;
        if(!l2) return l1;
        
        if(l1->val <= l2->val){
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else{
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};