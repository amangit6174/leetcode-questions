class Solution {
public:
    int sumofdigit(int n){
        int sum=0; 
        for(int i=1; n>0; i++){
            int digit=n%10;
            sum=sum+digit;
            n=n/10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
        if(i==sumofdigit(nums[i])){
            return i;
        }
        }
        return -1;
    }
};