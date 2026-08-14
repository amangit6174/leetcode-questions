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
    int lengthofLL(ListNode* head){
        int cnt=0;
        ListNode* temp=head;
        while(temp){
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int l=lengthofLL(head);
        int x=l-n+1;
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        if(x==1){
            ListNode* temp=head;
            head=head->next;
            temp->next=NULL;
            delete temp;
            return head;
        }
        int cnt=0;
        ListNode* temp=head;
        ListNode* prev=NULL;
        while(temp){
            cnt++;
            if(cnt==x){
                prev->next=prev->next->next;
                temp->next=NULL;
                delete temp;
                break;
            }
            prev=temp;
            temp=temp->next;
        }
        return head;
    }
};