class Solution {
public:
    int K,n;
    priority_queue<int,vector<int>,greater<int>> pq;

    void removeFromPQ(int num){
        vector<int> temp;
        while(!pq.empty()){
            int x= pq.top();
            pq.pop();
            if(x==num){
                break;
            }
            temp.push_back(x);
        }

        for(int &x: temp){
            pq.push(x);
        }
    }

    int solve(vector<int>& nums1, vector<int>& nums2, int sum,int min,int i,int count){
        if(count==K){
            return sum*min;
        }

        if(i>=n){
            return 0;
        }

        pq.push(nums2[i]);
        int take_i = solve(nums1,nums2,sum+nums1[i],pq.top(),i+1,count+1);
        removeFromPQ(nums2[i]);
        int not_take_i = solve(nums1,nums2,sum,min,i+1,count);
        return max(take_i, not_take_i);
    }
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        n = nums1.size();
        K=k;
        return solve(nums1,nums2,0,0,0,0);
    }
};
