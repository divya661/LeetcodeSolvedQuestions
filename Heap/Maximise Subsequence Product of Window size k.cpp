class Solution {
public:

    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<long long,long long>> v;
         priority_queue<long long,vector<long long>,greater<long long>> pq;

        for(int i=0;i<nums2.size();i++){
            v.push_back({nums1[i]*1LL,nums2[i]*1LL});
        }

        auto lambda = [&](auto& p1, auto& p2){
            return p1.second>p2.second;
        };
        
        sort(v.begin(),v.end(),lambda);

        long long curSum =0;
        for(int i=0;i<=k-1;i++){
            curSum += v[i].first;
            pq.push(v[i].first);
        }

        long long maxAns = curSum*(v[k-1].second*1LL);

        for(int i=k;i<nums2.size();i++){
            curSum = curSum + (v[i].first  - pq.top())*1LL;
            pq.pop();
            pq.push(v[i].first);  
            maxAns = max(maxAns, (long long)curSum*(v[i].second*1LL));
        }

        return maxAns;
    }
};
