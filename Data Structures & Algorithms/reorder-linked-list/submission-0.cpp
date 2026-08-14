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
    void reorderList(ListNode* head) {
        if(!head || !head->next)
            return;
        ListNode *slow=head,*fast=head->next;
        ListNode dummy(0);
        ListNode *tail=&dummy;
        while (fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *frontref=head,*backref=slow->next;
        slow->next=nullptr;
        ListNode *prev=nullptr,*curr=backref,*next;
        while(curr!=nullptr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        backref=prev;
        while(frontref && backref){
            tail->next=frontref;
            tail=tail->next;
            frontref=frontref->next;
            tail->next=backref;
            tail=tail->next;
            backref=backref->next;
            if(frontref)
                tail->next = frontref;

            if(backref)
                tail->next = backref;
        }
    }
};
