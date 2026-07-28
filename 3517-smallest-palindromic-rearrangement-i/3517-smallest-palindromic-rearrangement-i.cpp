class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.size();
        int mid=n/2-1;
        string a="";
        for(int i=0; i<=mid; i++){
            a.push_back(s[i]);
        }
        sort(a.begin(),a.end());
        string m="";
        if(n%2!=0){
            m.push_back(s[(n-1)/2]);
        }
        string b="";
        if(n%2==0){
            for(int i=mid+1; i<n; i++){
                b.push_back(s[i]);
            }
        }else{
            for(int i=mid+2; i<n; i++){
                b.push_back(s[i]);
            }
        }
        sort(b.begin(),b.end());
        reverse(b.begin(),b.end());
        string y=a+m+b;
        return y;
    }
};