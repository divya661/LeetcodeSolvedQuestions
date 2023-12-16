class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high =  *max_element(piles.begin(),piles.end());
        int mid;

        int noOfBanana = 0;

        while(low<high){
            mid = low + (high-low)/2;
            int curTime =0;
            for(auto &pile:piles){
                curTime += pile/mid + (pile%mid!=0 ? 1:0);
            }

            if(curTime>h){
                low = mid+1;
            } else if(curTime<=h){
                noOfBanana=mid;
                high = mid;
            }
        }

        return low;
    }
};
