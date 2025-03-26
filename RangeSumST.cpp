class NumArray {
public:
vector<int> seg;
int n = 0;
    NumArray(vector<int>& nums) {
        n = nums.size();
        seg.resize(4*n);

        auto solve = [&](int ind, int l, int r, auto& rsolve) -> void {
            if (l == r) {
                seg[ind] = nums[l];
                return;
            } 
            int mid = (l + r) / 2;
            rsolve(2*ind + 1, l, mid, rsolve);
            rsolve(2*ind + 2, mid + 1, r, rsolve);

            seg[ind] = seg[2*ind + 1] + seg[2*ind + 2];
        };

        solve(0, 0, n - 1, solve);
    }
    
    void update(int index, int val) {
        
        auto solve = [&](int ind, int l, int r, auto& rsolve) -> void {
            
            if (l == r) {
                seg[ind] = val;
                return;
            }

            int mid = ( l + r ) / 2;
            if (index <= mid)
                rsolve(2 * ind + 1, l, mid, rsolve);
            else
                rsolve(2 * ind + 2, mid + 1, r, rsolve);

            seg[ind] = seg[2*ind + 1] + seg[2*ind + 2];
        };

        solve(0, 0, n-1, solve);
    }
    
    int sumRange(int left, int right) {
        
        auto solve = [&](int ind, int l, int r, auto& rsolve) -> int {
            if (right < l || left > r) return 0;
            else if (right >= r && left <= l) return seg[ind];
            else {
                int mid = (l + r) / 2;
                return rsolve(2 * ind + 1, l, mid, rsolve) + rsolve(2*ind + 2, mid + 1, r, rsolve);
            }
        };

        return solve(0, 0, n - 1, solve);
    }
};
