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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*dummy=new ListNode(0);
        dummy->next=head;
        ListNode*temp=dummy;
        while(n!=0){
            temp=temp->next;
            n--;
        }
        ListNode*point=dummy;
        while(temp->next!=NULL){
            point=point->next;
            temp=temp->next;
        }
        point->next=point->next->next;
        return dummy->next;
    }
};
