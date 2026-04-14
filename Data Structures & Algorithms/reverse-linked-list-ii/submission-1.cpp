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
    ListNode* reverse(ListNode*root,int count,int right){
        if(!root)return NULL;
        ListNode*prev=NULL;
        ListNode*curr=root;
        ListNode*nex=root;
        while(nex && count!=right+1){
            nex=nex->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
            count++;
        }
        root->next=nex;
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head) return head;
        ListNode*lef=head;
        ListNode*dum=new ListNode(0);
        ListNode*prev=dum;
        dum->next=head;
        int i=1;
        while(i!=left){
            lef=lef->next;
            dum=dum->next;
            i++;
        }
        ListNode*temp=reverse(lef,left,right);
        dum->next=temp;
        return prev->next;
    }
};