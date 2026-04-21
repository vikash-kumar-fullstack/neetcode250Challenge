class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int total=0;
        int j=0;
        int k=0;
        while(j<g.size() && k<s.size()){
            if(g[j]<=s[k]){
                total++;
                j++;k++;
            }else{
                k++;
            }
        }
        return total;
    }
};