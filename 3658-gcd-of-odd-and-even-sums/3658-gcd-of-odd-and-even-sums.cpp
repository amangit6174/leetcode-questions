class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int gcd=1;
        for (int i=2; i<n*n; i++){
            if(n*n%i==0 && n*(n+1)%i==0){
            gcd=max (gcd, i);
            }
        }
        return gcd;
    }
};