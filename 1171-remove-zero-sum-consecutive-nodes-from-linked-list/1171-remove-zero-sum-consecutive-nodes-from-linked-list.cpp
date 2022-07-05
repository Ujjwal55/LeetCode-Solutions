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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        unordered_map<int, ListNode *> m;
        ListNode *curr = head;
        int sum = 0;
        m[0] = dummy;
        while(curr){
            sum += curr->val;
            int tot = sum;
            if(m.find(sum) != m.end()){
                ListNode *start = m[sum]->next;
                while(start && start != curr){
                    tot += start->val;
                    m.erase(tot);
                    start = start->next;
                }
                m[sum]->next = curr->next;
            }
            else{
                m[sum] = curr;
            }
            curr = curr->next;
        }
        return dummy->next;
    }
};