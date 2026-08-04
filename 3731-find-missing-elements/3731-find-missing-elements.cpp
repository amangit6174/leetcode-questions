class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>v;
        for(int i=1; i<nums.size(); i++ ){
            if(nums[i]>nums[i-1]){
                int k=nums[i]-nums[i-1]-1;
                int cnt=1;
                while(k>0){
                    v.push_back(nums[i-1]+cnt);
                    cnt++;
                    k--;
                }

            }else{
                continue;
            }
        }
        return v;
    }
};