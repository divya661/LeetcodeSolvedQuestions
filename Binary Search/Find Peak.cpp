class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return 0;
        }

        if(n==2){
            int ans = (nums[0]>=nums[1]) ? 0 : 1;
            return ans;
        }

        int low = 0;int high = n-1;int mid;

        while(low<=high){
            mid = low + (high-low)/2;
            cout<<low<<" "<<mid<<" "<<high<<"\n";
            int  ml = mid-1>=0 ? nums[mid-1] : INT_MIN;
           int mr =  mid+1<=n-1 ? nums[mid+1] : INT_MIN;
           cout<<ml<<" "<<nums[mid]<<" "<<mr<<"\n";

            if( ml<nums[mid] && nums[mid]>mr){
                return mid;
            } else if(ml<=nums[mid] && nums[mid]<=mr){
                low = mid+1;
            } else if((ml>=nums[mid] && nums[mid]>=mr) ){
                high = mid-1;
            } else if(ml>nums[mid] && nums[mid]<mr){
            
                high = mid-1;
            } 
        }

         return low;
    }
};
