#include "multiply.h"
#include "array_lazy.h"

extern int tree[4 * MAXN];
extern int max_tree[4 * MAXN];
extern int min_tree[4 * MAXN];
extern int lazy_add[4 * MAXN];
extern int mul_tree[4 * MAXN];
extern int lazy_mul[4 * MAXN];
extern int arr[MAXN];
extern int n;
// 区间更新：将区间 [l, r] 乘以 val（乘法更新）
void update_range_mul(int node, int start, int end, int l, int r, int val) {
    apply_lazy(node, start, end);
    if (start > r || end < l) return;
    if (start >= l && end <= r) {
        lazy_mul[node] *= val; // 乘法更新懒惰标记
        apply_lazy(node, start, end); // 应用懒惰标记
        return;
    }
    int mid = (start + end) / 2;
    update_range_mul(2 * node + 1, start, mid, l, r, val);
    update_range_mul(2 * node + 2, mid + 1, end, l, r, val);
    tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    max_tree[node] = max(max_tree[2 * node + 1], max_tree[2 * node + 2]);
    min_tree[node] = min(min_tree[2 * node + 1], min_tree[2 * node + 2]);
    mul_tree[node] = mul_tree[2 * node + 1] * mul_tree[2 * node + 2]; // 更新乘积
}
