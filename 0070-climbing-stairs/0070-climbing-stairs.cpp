class Solution {
public:
    unordered_map<int,int>memo;
    int climbStairs(int n) {
        if(memo.count(n)){
            return memo[n];
        }
        if(n==0){
            return 0;
        }if(n==1){
            return 1;
        }if(n==2){
            return 2;
        }
        int result = climbStairs(n-1)+climbStairs(n-2);
        memo[n]=result;
        return result;
    }
};