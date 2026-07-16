class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> mx(n);
        mx[0]=nums[0];
        for(int i=1; i<n; i++){
            mx[i]=max(mx[i-1],nums[i]);
        }
        vector<int>prefixGcd;
        for(int i=0; i<n; i++){
            int y=gcd(nums[i], mx[i]);
            prefixGcd.push_back(y);
        }
        sort(prefixGcd.begin(),prefixGcd.end());
        long long sum=0;
        int left=0;
        int right=n-1;
        while(left<right){
            int z=gcd(prefixGcd[left],prefixGcd[right]);
            sum=sum+z;
            left++;
            right--;
        }
        return sum;
    }
};