// stores max "value" of the ranges in seg[i];
vector<int> seg;
int n;
    void build(vector<int>& nums, int i, int l, int r) {
        if (l == r) {
            seg[i] = nums[l]; 
            return;
        }

        int mid = l + (r - l) / 2;
        build(nums, 2*i+1, l, mid);
        build(nums, 2*i+2, mid + 1, r);

        seg[i] = seg[2*i+1] >= seg[2*i+2] ? seg[2*i+1] : seg[2*i+2];

    }

    void update(int i, int l, int r, int indx) {
        if (l == r) {
            seg[i] = -1;
            return;
        }

        int mid = l + (r - l) / 2;

        if (indx <= mid) {
            update(2*i+1, l, mid, indx);
        } else {
            update(2*i+2, mid +1, r, indx);
        }

        seg[i] = seg[2*i+1] >= seg[2*i+2] ? seg[2*i+1] : seg[2*i+2];
    }

    int query(vector<int>& nums, int i, int l, int r, int a, int b) {
        if (r < a || l > b) return -1;
        if (l >= a && r <= b) return seg[i];

        int mid = l + (r - l) / 2;
        int left = query(nums, 2*i+1, l, mid, a, b);
        int right =  query(nums, 2*i+2, mid+1, r, a, b);

        if (left == -1) return right;
        if (right == -1) return left;

        return max(left, right);
    }
