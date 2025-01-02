#include "add.h"
#include "array_lazy.h"
extern int tree[4 * MAXN];
extern int max_tree[4 * MAXN];
extern int min_tree[4 * MAXN];
extern int lazy_add[4 * MAXN];
extern int mul_tree[4 * MAXN];
extern int lazy_mul[4 * MAXN];
extern int arr[MAXN];
extern int n;
// 区间更新：将区间 [l, r] 增加 val
void update_range_add(int node, int start, int end, int l, int r, int val) {
    apply_lazy(node, start, end);
    if (start > r || end < l) return;
    if (start >= l && end <= r) {
        lazy_add[node] += val;
        apply_lazy(node, start, end);
        return;
    }
    int mid = (start + end) / 2;
    update_range_add(2 * node + 1, start, mid, l, r, val);
    update_range_add(2 * node + 2, mid + 1, end, l, r, val);
    tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    max_tree[node] = max(max_tree[2 * node + 1], max_tree[2 * node + 2]);
    min_tree[node] = min(min_tree[2 * node + 1], min_tree[2 * node + 2]);
}
