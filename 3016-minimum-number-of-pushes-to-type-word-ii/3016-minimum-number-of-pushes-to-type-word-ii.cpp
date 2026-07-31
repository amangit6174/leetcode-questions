class Solution {
public:
    int minimumPushes(string word) {
        int mpp[26]={0};
        for(int i=0; i<word.size(); i++){
            mpp[word[i]-'a']++;
        }
        sort(mpp,mpp+26,greater<int>());
        int cnt=0;
        for(int i=0; i<26; i++){
            if(mpp[i]>0){
                cnt++;
            }
        }
        int ans=0;
        if(cnt<8){
            int i=0;
            while(mpp[i]>0){
                ans=ans+mpp[i];
                i++;
            }
        }else if(cnt<16 && cnt>=8){
            int i=0;
            while(i<8){
                ans=ans+mpp[i];
                i++;
            }
            while(mpp[i]>0){
                ans=ans+2*mpp[i];
                i++;
            }
        }else if(cnt>=16 && cnt<24){
             int i=0;
            while(i<8){
                ans=ans+mpp[i];
                i++;
            }
            while(i>=8 && i<16){
                ans=ans+2*mpp[i];
                i++;
            }
            while(mpp[i]>0){
                ans=ans+3*mpp[i];
                i++;
            }
        }else{
            int i=0;
            while(i<8){
                ans=ans+mpp[i];
                i++;
            }
            while(i>=8 && i<16){
                ans=ans+2*mpp[i];
                i++;
            }
            while(i<24 && i>=16){
                ans=ans+3*mpp[i];
                i++;
            }
            while(i<26 && mpp[i]>0){
                ans=ans+4*mpp[i];
                i++;
            }
        }
    return ans;
    }
};