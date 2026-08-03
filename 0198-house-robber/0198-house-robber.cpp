class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0){
            return  0;
        }else if(nums.size()==1){
            return nums[0];
        }else if(nums.size()==2){
            return max(nums[0],nums[1]);
        }else if(nums.size()==3){
            return max(nums[0]+nums[2],nums[1]);
        }
        else {
        int profit[nums.size()];
        profit[0]=nums[0];
        profit[1]=nums[1];
        profit[2]=nums[2]+nums[0];
        for(int i=3; i<nums.size(); i++){
            profit[i]=max(profit[i-2],profit[i-3])+nums[i];
        }
        return max(profit[nums.size()-1],profit[nums.size()-2]);
        }
    }
};