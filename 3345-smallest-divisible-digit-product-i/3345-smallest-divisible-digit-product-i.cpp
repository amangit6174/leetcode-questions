class Solution {
public:
    int productofdigit(int n){
        int p=1;
        while(n>0){
            int digit=n%10;
            p=p*digit;
            n=n/10;
        }
        return p;
    }
    int smallestNumber(int n, int t) {
        int x=n;
        while(productofdigit(x)%t!=0){
            x++;
        }
        return x;
    }
};