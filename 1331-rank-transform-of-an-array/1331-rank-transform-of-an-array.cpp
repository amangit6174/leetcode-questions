class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.empty()) return arr;
        map<int,int> mpp;
        vector<int> v=arr;
        sort(v.begin(), v.end());
        int k=1;
        mpp[v[0]]=k;
        for(int i=1; i<v.size(); i++){
            if(v[i]==v[i-1]){
                mpp[v[i]]=mpp[v[i-1]];
            }else{
                k++;
                mpp[v[i]]=k;
            }
        }
        for(int i=0; i<arr.size(); i++){
            arr[i]=mpp[arr[i]];
        }
        return arr;
    }
};