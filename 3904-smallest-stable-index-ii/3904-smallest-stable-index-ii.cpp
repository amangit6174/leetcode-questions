class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int> premax(nums.size(),0);
        vector<int> premin(nums.size(),0);
        premax[0]=nums[0];
        for(int i=1; i<nums.size(); i++){
            premax[i]=max(premax[i-1],nums[i]);
        }
        premin[nums.size()-1]= nums[nums.size()-1];
        for(int i=nums.size()-2; i>=0; i--){
            premin[i]=min(premin[i+1],nums[i]);
        }
        // for(int i=0; i<premax.size(); i++){
        //     cout<<premax[i]<<" ";
        // }
        for(int j=0; j<nums.size(); j++){
            if(premax[j]-premin[j]<=k){
                return j;
            }
        }
        return -1;
    }
};