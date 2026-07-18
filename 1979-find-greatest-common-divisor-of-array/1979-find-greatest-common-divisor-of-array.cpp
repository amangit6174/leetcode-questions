class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mx= *max_element(nums.begin(),nums.end());
        int mn= *min_element(nums.begin(),nums.end());
        int ans=1;
        for(int i=1; i<=mn; i++){
            if(mx%i==0 && mn%i==0){
                ans=max(i,ans);
            }
        }
        return ans;
    }
};