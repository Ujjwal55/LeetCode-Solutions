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
    ListNode *intersection(ListNode *headA, ListNode *headB, int n, int m){
        if(headA == NULL || headB == NULL) return NULL;
        if(n > m){
            return intersection(headA->next, headB, n-1, m);
        }
        else if(m > n){
            return intersection(headA, headB->next, n, m-1);
        }
        else if(n == m && headA == headB){
            return headA;
        }
        else return intersection(headA->next, headB->next, n-1, m-1);
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // if(headA == NULL || headB == NULL) return 0;
        // ListNode *temp1 = headA, *temp2 = headB;
        // while(temp1 != temp2){
        //     temp1 = temp1 == NULL ? headB : temp1->next;
        //     temp2 = temp2 == NULL ? headA : temp2->next;
        // }
        // return temp1;
        ListNode *temp1 = headA, *temp2 = headB;
        int n = 0, m = 0;
        while(temp1){
            n++;
            temp1 = temp1->next;
        }
        while(temp2){
            m++;
            temp2 = temp2->next;
        }
        return intersection(headA, headB, n, m);
    }
};