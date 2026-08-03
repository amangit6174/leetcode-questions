class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mpp;
        for(int i=0; i<nums.size(); i++){
            mpp[nums[i]]++;                        // key,value
        }
        vector<pair<int,int>> freq;
        for(auto it: mpp){
            freq.push_back({it.second,it.first});  // value,key
        }
        vector<int>v;
        sort(freq.begin(),freq.end(),greater<pair<int,int>>());
            for(auto it: freq){
                if(k>0){
                v.push_back(it.second);
                }else{
                    break;
                }
                k--;
            }
        return v;
    }
};