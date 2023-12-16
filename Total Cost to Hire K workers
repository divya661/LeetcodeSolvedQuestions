class Solution {
public:
    long long totalCost(vector<int>& costs, int k,
     int candidates) {
         int n = costs.size();
         long long total_cost= 0;
        priority_queue<int,vector<int>,greater<int>> pq1,pq2;
        int i=0,cur_hired_no=0, j=n-1;

        while(cur_hired_no<k){
            while(pq1.size()<candidates && i<=j){
                pq1.push(costs[i++]);
            }

            while(pq2.size()<candidates && j>=i){
                pq2.push(costs[j--]);
            }

            int min_pq1 = pq1.size()>0 ? pq1.top(): INT_MAX;
            int min_pq2 = pq2.size()>0 ? pq2.top():INT_MAX;

            if(min_pq1<=min_pq2){
                total_cost += min_pq1*1LL;
                pq1.pop();
            } else {
                total_cost += min_pq2*1LL;
                pq2.pop();
            }

            cur_hired_no++;
        }
     
        return total_cost;
    }
};
