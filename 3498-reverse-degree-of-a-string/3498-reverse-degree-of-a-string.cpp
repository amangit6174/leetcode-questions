class Solution {
public:
    int reverseDegree(string s) {
        int ans=0;
        for(int i=0; i<s.size(); i++){
            int x = ('a'-s[i]);
            ans = ans+ (x+26)*(i+1);
        }
        return ans;
    }
};