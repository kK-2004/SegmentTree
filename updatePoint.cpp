#include "updatePoint.h"

extern int tree[4 * MAXN];
extern int max_tree[4 * MAXN];
extern int min_tree[4 * MAXN];
extern int lazy_add[4 * MAXN];
extern int mul_tree[4 * MAXN];
extern int lazy_mul[4 * MAXN];
extern int arr[MAXN];
extern int n;
//单点更新
void update_point(int node, int start, int end, int idx, int new_val) {
    apply_lazy(node, start, end);
    if (start == end) {
        arr[idx] = new_val;
        tree[node] = new_val;
        max_tree[node] = new_val;
        min_tree[node] = new_val;
    }
    else {
        int mid = (start + end) / 2;
        if (start <= idx && idx <= mid) {
            update_point(2 * node + 1, start, mid, idx, new_val);
        }
        else {
            update_point(2 * node + 2, mid + 1, end, idx, new_val);
        }
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        max_tree[node] = max(max_tree[2 * node + 1], max_tree[2 * node + 2]);
        min_tree[node] = min(min_tree[2 * node + 1], min_tree[2 * node + 2]);
    }
}
