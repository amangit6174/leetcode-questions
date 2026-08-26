class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<int> v;
        int multiple=0;
        for(int i=1; multiple<=nums[nums.size()-1]; i++){
            multiple=k*i;
            v.push_back(multiple);
        }
        int j=0;
        for(int i=0; i<nums.size() && j<v.size(); i++){
            if(nums[i]==v[j]){
                j++;
            }
            else if(nums[i]<v[j]){
                continue;
            }
            else if(nums[i]>v[j]){
                return v[j];
            }
        }
        return v[j];
    }
};