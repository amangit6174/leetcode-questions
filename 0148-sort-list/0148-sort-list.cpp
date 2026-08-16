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
    ListNode* midLL(ListNode* low, ListNode* high){
        ListNode* slow=low;
        ListNode* fast=low;
        while(fast!=high && fast->next!=high){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    void mergeLL(ListNode* low, ListNode* mid, ListNode* high){
        vector<int> v;
        ListNode* left=low;
        ListNode* right=mid->next;

        while(left!=mid->next && right!=high->next){
            if(left->val <= right->val){
                v.push_back(left->val);
                left=left->next;
            }else{
                v.push_back(right->val);
                right=right->next;
            }
        }
        while(left!=mid->next){
            v.push_back(left->val);
            left=left->next;
        }
        while(right!=high->next){
            v.push_back(right->val);
            right=right->next;
        }
        ListNode* curr=low;
        for(auto it: v){
            curr->val=it;
            curr=curr->next;
        }

    }
    void mergesortLL(ListNode* low, ListNode* high){
        if(low==high){
            return;
        }
        ListNode* mid=midLL(low, high);

        mergesortLL(low, mid);
        mergesortLL(mid->next, high);
        mergeLL(low,mid,high);
    }
    ListNode* sortList(ListNode* head){
        if(head==NULL){
            return NULL;
        }
        ListNode* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        mergesortLL(head, temp);
        return head;
    }
};