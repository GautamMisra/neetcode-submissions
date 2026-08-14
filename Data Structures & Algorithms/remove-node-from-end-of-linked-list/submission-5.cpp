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
        if (!head || !head->next)
            return nullptr;
        ListNode *temp;
        ListNode *prev=nullptr,*curr=head,*next;
        while(curr!=nullptr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        head=prev;
        curr=head;
        if(n==1){
    ListNode* temp1 = head;
    head = head->next;
    delete temp1;

    // reverse back immediately
    ListNode *prev1=nullptr,*curr1=head,*next1;
    while(curr1){
        next1=curr1->next;
        curr1->next=prev1;
        prev1=curr1;
        curr1=next1;
    }

    return prev1;
}
        for(int i=1;i<n-1 && curr!=nullptr;i++){
            curr=curr->next;
        }
        if (curr == nullptr || curr->next == nullptr) {
            return head; 
        }   
        temp=curr->next;
        curr->next=temp->next;
        delete temp;
        ListNode *prev1=nullptr,*curr1=head,*next1;
        while(curr1!=nullptr){
            next1=curr1->next;
            curr1->next=prev1;
            prev1=curr1;
            curr1=next1;
        }
        head=prev1;
        return head;
    }
};
