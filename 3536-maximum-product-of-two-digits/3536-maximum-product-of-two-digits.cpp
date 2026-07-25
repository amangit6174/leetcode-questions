class Solution {
public:
    int maxProduct(int n) {
        vector<int>v;
        while(n>0){
            int digit=n%10;
            v.push_back(digit);
            n=n/10;
        }
        sort(v.begin(), v.end());
        int mx=v[v.size()-1];
        int mxi=v[v.size()-2];
        long long ans=mx*mxi;
        return ans;
    }
};