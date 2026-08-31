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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans={-1,-1};
        vector<int> nums;
        ListNode* temp=head;
        while(temp!=NULL){
            nums.push_back(temp->val);
            temp=temp->next;
        }
        if(nums.size()<3){
            return ans;
        }
        vector<int> a;
        for(int i=1; i<nums.size()-1; i++){
            if((nums[i-1]<nums[i] && nums[i]>nums[i+1]) || (nums[i-1]>nums[i] && nums[i]<nums[i+1])){
                a.push_back(i);
            }
        }
        if(a.size()<2){
            return ans;
        }
        int mxdis=a[a.size()-1]-a[0];
        int mndis=mxdis;
        for(int i=1; i<a.size(); i++){
            mndis=min(mndis, a[i]-a[i-1]);
        }
        ans[0]=mndis;
        ans[1]=mxdis;
        return ans;
    }
};