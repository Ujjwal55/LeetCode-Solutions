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
        int n = 0, m = 0;
        ListNode *temp1 = headA, *temp2 = headB;
        while(temp1){
            n++;
            temp1 = temp1->next;
        }
        while(temp2){
            m++;
            temp2 = temp2->next;
        }
        int diff = abs(m-n);
        temp1 = headA, temp2 = headB;
        if(n > m){
            int i = 0;
            while(i < diff){
                temp1 = temp1->next;
                i++;
            }
        }
        else{
            int i = 0;
            while(i < diff){
                temp2 = temp2->next;
                i++;
            }
        }
        while(temp1 && temp2){
            if(temp1 == temp2) return temp1;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return 0;
    }
};