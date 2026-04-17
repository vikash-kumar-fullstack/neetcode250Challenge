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
    ListNode*reverse(ListNode*head){
        if(!head)return NULL;
        ListNode*prev=NULL;
        ListNode*curr=head;
        ListNode*nex=head;
        while(nex){
            nex=nex->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode*slow=head;
        ListNode*hare=head;
        while(hare->next && hare->next->next){
            slow=slow->next;
            hare=hare->next->next;
        }
        ListNode*sec=reverse(slow->next);
        slow->next=NULL;
        ListNode*temp=head;
        ListNode*ans=head;
        ListNode*temp2=sec;
        while(temp && temp2){
            temp=ans->next;
            ans->next=sec;
            temp2=sec->next;
            sec->next=temp;
            sec=temp2;
            ans=temp;
        }
    }
};
