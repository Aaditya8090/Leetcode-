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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>> , greater<pair<int, ListNode*>>>pq;
        for(int i=0; i<lists.size(); i++){
            if(lists[i] != nullptr)
                pq.push({lists[i]->val, lists[i]});
        }

        ListNode *dummyNode = new ListNode(0);  // first node is dummy
        ListNode *last = dummyNode;
        while(!pq.empty()){
            auto [a, b] = pq.top();
            pq.pop();

            last->next = b;
            last = b;

            if(b->next != nullptr){
                pq.push({b->next->val, b->next});
            }
        }
        return dummyNode->next;
    }
};