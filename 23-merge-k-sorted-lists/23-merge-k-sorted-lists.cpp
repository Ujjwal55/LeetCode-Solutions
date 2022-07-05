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
    ListNode *merge(ListNode *left, ListNode *right){
        if(!left) return right;
        if(!right) return left;
        ListNode *temp1 = left, *temp2 = right;
        ListNode *temp = NULL;
        while(left && right){
            if(left->val <= right->val){
                while(left && left->val <= right->val){
                    temp = left;
                    left = left->next;
                }
                temp->next = right;
            }
            else{
                while(right && right->val <= left->val){
                    temp = right;
                    right = right->next;
                }
                temp->next = left;
            }
        }
        if(temp1->val <= temp2->val) return temp1;
        else return temp2;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0) return NULL;
        if(n == 1) return lists[0];
        ListNode *first = lists[0];
        ListNode *second = lists[1];
        ListNode *head = merge(first, second);
        for(int i = 2 ; i < n ; i++){
            head = merge(head, lists[i]);
        }
        return head;
    }
};