class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        sort(potions.begin(),potions.end());

        for(auto &spell: spells){
            int cur_pairs =0;
            int low=0;
            int high = potions.size()-1;

            while(low<=high){
                int mid =  low + (high-low)/2;
                long long cur_power = (long long)potions[mid]*spell;
                
                if(cur_power >= success*1LL){
                    cur_pairs += (high-mid+1); 
                    high = mid-1;
                } 


                 if(cur_power<success*1LL){
                    low = mid+1; 
                 }
            }
           ans.push_back(cur_pairs);

        }

       return ans;
    }
};