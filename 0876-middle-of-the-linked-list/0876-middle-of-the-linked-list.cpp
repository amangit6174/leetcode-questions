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
    ListNode* middleNode(ListNode* head) {
        int cnt=0;
        ListNode* temp=head;
        while(temp){
            cnt++;
            temp=temp->next;
        }
        if(cnt%2!=0){
            int x=(cnt+1)/2;
            ListNode* mover=head;
            for(int i=1; i<x; i++){
                mover=mover->next;
            }
        return mover;
        }
            int x=cnt/2;
            ListNode* mover=head;
            for(int i=1; i<=x; i++){
                mover=mover->next;
            }
        return mover;
        
    }
};