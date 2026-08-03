class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int profit[n]; 
        if(n==1){
            return nums[0];
        }else if(n==2){
            return max(nums[0],nums[1]);
        }else if(n==3){
            return max(nums[0],max(nums[2],nums[1]));
        }else{
            profit[0]=nums[0];
            profit[1]=nums[1];
            profit[2]=nums[0]+nums[2];
            for(int i=3; i<n-1; i++){
                profit[i]=max(profit[i-2],profit[i-3])+nums[i];
            }
            int ans1=max(profit[n-2],profit[n-3]);
            profit[n-1]=nums[n-1];
            profit[n-2]=nums[n-2];
            profit[n-3]=nums[n-1]+nums[n-3];
            for(int i=n-4; i>=0; i--){
                profit[i]=max(profit[i+2],profit[i+3])+nums[i];
            }
            int ans2=max(profit[1],profit[2]);
            return max(ans1,ans2);
        }
    }
};