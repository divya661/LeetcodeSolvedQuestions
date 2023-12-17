class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        int prev_temp = 0,i=0;
        vector<int> ans(n,0);
        stack<pair<int,int>> st;

        for(int i=n-1;i>=0;i--){
              while(!st.empty() && st.top().first<=temperatures[i]){
                        st.pop();
                }
              
            if(st.size()==0){
                st.push({temperatures[i],i});
                ans[i] = 0;
            } else  if(st.top().first>temperatures[i]){
                    ans[i] = st.top().second-i;
                    st.push({temperatures[i],i});
            }        
        }      
        
        
        return ans;
    }
};