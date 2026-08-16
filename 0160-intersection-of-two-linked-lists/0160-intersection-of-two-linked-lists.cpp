/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int lengthLL(ListNode* head){
        int cnt=0;
        ListNode* temp=head;
        while(temp){
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int a=lengthLL(headA);
        int b=lengthLL(headB);
        if(a<=b){
            int x=b-a;
            ListNode* tempB=headB;
            ListNode* tempA=headA;
            while(x!=0){
                tempB=tempB->next;
                x--;
            }
            while(tempA!=tempB && tempA!=NULL){
                tempA=tempA->next;
                tempB=tempB->next;
            }
            return tempA;
        }else{
            int x=a-b;
            ListNode* tempA=headA;
            ListNode* tempB=headB;
            while(x!=0){
                tempA=tempA->next;
                x--;
            }
            while(tempA!=tempB && tempA!=NULL){
                tempA=tempA->next;
                tempB=tempB->next;
            }
            return tempA;
        }
    }
};