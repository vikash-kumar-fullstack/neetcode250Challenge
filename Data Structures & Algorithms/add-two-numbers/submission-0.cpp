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
    ListNode* reverse(ListNode*root){
        if(!root)return NULL;
        ListNode*prev=NULL;
        ListNode*curr=root;
        ListNode*nex=root;
        while(nex){
            nex=nex->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*fir=l1;
        ListNode*sec=l2;
        ListNode*dum=new ListNode(0);
        int carry=0;
        ListNode*head=dum;
        while(fir && sec){
            int data=fir->val+sec->val+carry;
            ListNode*temp=new ListNode(data%10);
            carry=data/10;
            dum->next=temp;
            dum=dum->next;
            fir=fir->next;
            sec=sec->next;
        }
        while(fir){
            int data=fir->val+carry;
            ListNode*temp=new ListNode(data%10);
            carry=data/10;
            dum->next=temp;
            dum=dum->next;
            fir=fir->next;
        }
        while(sec){
            int data=sec->val+carry;
            ListNode*temp=new ListNode(data%10);
            carry=data/10;
            dum->next=temp;
            dum=dum->next;
            sec=sec->next;
        }
        if(carry)dum->next=new ListNode(carry%10);
        return head->next;
    }
};
