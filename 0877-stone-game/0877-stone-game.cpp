class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int sum=0;
        int n=piles.size();
        for(int i=0; i<n/2; i++){
            sum=sum+piles[i];
        }
        int currentsum=sum;
        for(int i=n-1; i>=n-n/2; i--){
            sum=sum-piles[n-1-i];
            sum=sum+piles[i];
            currentsum=max(sum,currentsum);
        }
        int totalsum=0;
        for(int i=0; i<n; i++){
            totalsum +=piles[i];
        }
        if(currentsum>totalsum/2){
            return true;
        }else{
            return false;
        }
    }
};