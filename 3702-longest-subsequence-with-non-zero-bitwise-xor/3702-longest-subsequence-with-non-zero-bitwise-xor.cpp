class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        // if(nums.size()==1){
        //     if(nums[0]!=0){
        //         return 1;
        //     }
        //     return 0;
        // }
        // int ans=0;
        // int left=0;
        // int right=1;
        // int x=nums[left];
        // while(left<right && right<nums.size()){
        //     x = x^nums[right];
        //    while(x==0){
        //     x=x^nums[left];
        //     left++;
        //    }
        //    ans=max(ans,right-left+1);
        //    right++;

        // }
        // return ans;
        int x=0;
        for(int i=0; i<nums.size(); i++){
            x=x^nums[i];
        }
        if(x!=0){
            return nums.size();
        }
        if(x==0){
            int a;
            for(int i=0; i<nums.size(); i++){
                if(nums[i]!=0){
                    return nums.size()-1;
                }
            }
        }
        return 0;
    }
};