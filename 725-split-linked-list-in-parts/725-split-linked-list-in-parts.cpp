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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode *> ans;
        int cnt = 0;
        ListNode *temp = head;
        while(temp){
            cnt++;
            temp = temp->next;
        }
        int n = cnt/k;
        int rem = cnt - k * n;
        temp = head;
        if(n < 1){
            while(temp){
                ListNode *t = new ListNode(temp->val);
                ans.push_back(t);
                temp = temp->next;
            }
            int j = k-cnt;
            while(j--){
                ans.push_back(NULL);
            }
        }
        else{
            while(temp){
                int j = 1;
                ListNode *curr = temp, *t = temp;
                temp = temp->next;
                while(j < n){
                    t->next = temp;
                    temp = temp->next;
                    t = t->next;
                    j++;
                }
                if(rem > 0){
                    t->next = temp;
                    temp = temp->next;
                    t = t->next;
                    rem--;
                }
                t->next = NULL;
                ans.push_back(curr);
            }
        }
        return ans;
    }
};