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
    bool hasCycle(ListNode *head) {
        // vector<ListNode*> v;
        // ListNode* temp=head->next;
        // v.push_back(head);
        // while(temp){
        //     if(count(v.begin(),v.end(),temp)){
        //         return true;
        //     }
        //     v.push_back(temp->next);
        //     temp=temp->next;
        // }
        // return false;
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                return true;
            }
        }
        return false;
    }
};