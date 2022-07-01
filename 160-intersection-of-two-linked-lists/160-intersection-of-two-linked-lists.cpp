/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *temp1 = headA;
        while(headA){
            ListNode *temp2 = headB;
            while(temp2){
                if(headA == temp2) return headA;
                temp2 = temp2->next;
            }
            headA = headA->next;
        }
        return 0;
    }
};