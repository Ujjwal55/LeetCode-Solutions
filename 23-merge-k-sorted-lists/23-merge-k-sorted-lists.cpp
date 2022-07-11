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
    struct cmp{
        bool operator()(ListNode *l1, ListNode *l2){
            return l1->val > l2->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode *, vector<ListNode*>, cmp> pq;
        for(auto it : lists){
            if(it) pq.push(it);
        }
        if(pq.empty()) return NULL;
        ListNode *result = pq.top();
        pq.pop();
        if(result->next) pq.push(result->next);
        ListNode *tail = result;
        while(!pq.empty()){
            tail->next = pq.top();
            pq.pop();
            tail = tail->next;
            if(tail->next) pq.push(tail->next);
        }
        return result;
    }
};