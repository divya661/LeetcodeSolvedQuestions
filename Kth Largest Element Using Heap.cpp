class Solution {
public:
    struct Heap {
        vector<int> v;
        int n;

        Heap(int i=0): n(i){
            v = vector<int>(n);
        }
    };

    void swap(int& a,int& b){
        int temp = a;
        a = b;
        b= temp;
    }

    inline int parent(int i){
        return (i-1)/2;
    }

    inline int left(int i){
        return 2*i+1;
    }

    inline int right(int i){
        return 2*i+2;
    }

    void heapify(Heap& h, int i){
        int l = left(i);
        int r = right(i);
        int p = i;

        if(l<h.n  && h.v[l]>h.v[p]){
            p = l;
        } 

        if(r<h.n && h.v[r]>h.v[p]){
            p = r;
        } 

        if(p!=i){
            swap(h.v[p],h.v[i]);
            heapify(h,p);
        }
    }

    int extractMax(Heap& h){
        if(h.n==0){
            return -1;
        }

        int m = h.v[0];
        // cout<<m<<" ";
        h.v[0] = h.v[h.n-1];
        heapify(h,0);

        return m;
    }

    int KthLargest(Heap& h,int k){
        for(int i=1;i<k;i++){
            extractMax(h);
        }

        for(int i=0;i<h.n;i++){
            cout<<h.v[i]<<" ";
        }
        cout<<"\n";

        return extractMax(h);
    }

    int findKthLargest(vector<int>& nums, int k) {
       Heap h(nums.size());
       h.v = nums;
       for(int i=nums.size()/2-1;i>=0;i--){
           heapify(h,i);
       }
       return KthLargest(h,k);
    }
};
