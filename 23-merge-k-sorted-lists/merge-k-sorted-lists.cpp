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
    ListNode *last;
    void addNewNode(ListNode*&root, ListNode*nw){
        if(root == nullptr){
            root = nw;
            last = nw;
        }else{
            last->next = nw;
            last = nw;
        }
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *ans = nullptr; last = nullptr;

        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>> , greater<pair<int, ListNode*>>>pq;
        for(int i=0; i<lists.size(); i++){
            if(lists[i] != nullptr)
                pq.push({lists[i]->val, lists[i]});
        }

        while(!pq.empty()){
            auto [a, b] = pq.top();
            // cout << a << " ";
            pq.pop();

            ListNode *newNode = new ListNode(a);
            cout << newNode <<" ";
            addNewNode(ans, newNode);

            if(b->next != nullptr){
                pq.push({b->next->val, b->next});
            }
        }
        return ans;
    }
};