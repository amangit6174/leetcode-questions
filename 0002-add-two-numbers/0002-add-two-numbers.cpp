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
    ListNode* deletetail(ListNode* head){
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        ListNode* temp=head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        ListNode* t=temp->next;
        temp->next=NULL;
        delete t;
        return head;
    }


    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1=l1;
        ListNode* t2=l2;
        ListNode* a=new ListNode(0);
        ListNode* ans=a;
        while(t1!=NULL && t2!=NULL){
            ans->val=ans->val+t1->val+t2->val;
            t1=t1->next;
            t2=t2->next;
            if(ans->val>=10){
                ans->val=ans->val-10;
                ans->next=new ListNode(1);
                ans=ans->next;
            }else{
            ans->next=new ListNode(0);
            ans=ans->next;
            }
        }
        while(t1!=NULL){
            ans->val=ans->val+t1->val;
            t1=t1->next;
            if(ans->val>=10){
                ans->val=ans->val-10;
                ans->next=new ListNode(1);
                ans=ans->next;
            }else{
            ans->next=new ListNode(0);
            ans=ans->next;
            }
        }
        while(t2!=NULL){
            ans->val=ans->val+t2->val;
            t2=t2->next;
           if(ans->val>=10){
                ans->val=ans->val-10;
                ans->next=new ListNode(1);
                ans=ans->next;
            }else{
            ans->next=new ListNode(0);
            ans=ans->next;
            }
        }
        if(ans->val==0 && a->next!=NULL){
            deletetail(a);
        }
    return a;
    }
};