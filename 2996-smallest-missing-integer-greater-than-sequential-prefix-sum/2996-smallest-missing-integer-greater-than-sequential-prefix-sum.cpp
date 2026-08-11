class Solution {
public:
    int missingInteger(vector<int>& nums) {
        if(nums.size()==1){
            return nums[nums.size()-1]+1;
        }
        int sum=nums[0];
        int x=0;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]-nums[i-1]==1){
            sum=sum+nums[i];
            }else{
                x=i;
                break;
            }
        }
        if(x==0){
            return sum;
        }else{
            int ans=sum;
            sort(nums.begin()+x, nums.end());
            for(int i=x-1; i<nums.size(); i++){
                if(nums[i]==ans){
                    ans++;
                }
            }
            return ans;
        }
    }
};