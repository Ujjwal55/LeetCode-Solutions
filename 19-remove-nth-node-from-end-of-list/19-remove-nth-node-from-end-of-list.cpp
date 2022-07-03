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
    int remove(ListNode *head, int n){
        if(!head->next) return 0;
        int cnt = remove(head->next, n) + 1;
        if(cnt == n){
            head->next = head->next->next;
        }
        return cnt;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // if(!head || !head->next) return NULL;
        // // ListNode *a = new ListNode(-1);
        // // a->next = head;
        // ListNode *prev = NULL;
        // ListNode *curr = head;
        // int i = 1;
        // ListNode *temp = head;
        // // head = a;
        // while(temp){
        //     if(i > n){
        //         prev = curr;
        //         curr = curr->next;
        //     }
        //     i++;
        //     temp = temp->next;
        // }
        // if(prev == NULL) return head->next;
        // ListNode *p = prev->next;
        // prev->next = prev->next->next;
        // delete p;
        // return head;
        int num = remove(head, n);
        return num < n ? head->next : head;
    }
};
