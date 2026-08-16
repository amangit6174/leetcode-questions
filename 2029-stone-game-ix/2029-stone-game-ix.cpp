class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        // int sum=0;
        // int cnt=0;
        // for(int i=0; i<stones.size(); i++){
        //     sum+=stones[i];
        //     if(stones[i]%3!=0){
        //         cnt++;
        //     }
        // }
        // int n=stones.size();
        // if(n%2==0){
        //     if(sum%3==0){
        //         if(cnt>0){
        //             return true;
        //         }else{
        //             return false;
        //         }
        //     }else{
        //         return false;
        //     }
        // }
        // else{
        //     if(sum%3==0){
        //         return false;
        //     }else{
        //         if(n==1){
        //             return false;
        //         }
        //         if(cnt==0){
        //             return false;
        //         }else{
        //             return true;
        //         }
        //     }
        // }
        int a = 0;
        int b = 0;
        int c = 0;

        for (int i : stones) {
            if (i % 3 == 0) {
                a++;
            }
            else if (i % 3 == 1) {
                b++;
            }
            else {
                c++;
            }
        }

        if (a % 2 == 0) {
            return b > 0 && c > 0;
        }

        return abs(b - c) > 2;
    }
};