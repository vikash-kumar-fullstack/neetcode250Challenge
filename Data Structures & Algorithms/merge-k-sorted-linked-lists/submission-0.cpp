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
    class comparator{
        public:
        bool operator()(ListNode*a,ListNode*b){
        return a->val>b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,comparator>que;
        for(int i=0;i<lists.size();i++){
            if(lists[i])
            que.push(lists[i]);
        }
        ListNode*head=NULL;
        ListNode*tail=NULL;
        while(!que.empty()){
            ListNode*temp=que.top();
            que.pop();
            
            if(head==NULL){
                head=tail=temp;
            }
            else{
                tail->next=temp;
                tail=temp;
            }
            if(temp->next){
                que.push(temp->next);
            }
        }
        if (tail) tail->next = NULL;
        return head;
    }
};