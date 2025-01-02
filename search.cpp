#include "search.h"
#include "array_lazy.h"

 
extern int tree[4 * MAXN];
extern int max_tree[4 * MAXN];
extern int min_tree[4 * MAXN];
extern int lazy_add[4 * MAXN];
extern int mul_tree[4 * MAXN];
extern int lazy_mul[4 * MAXN];
extern int arr[MAXN];
extern int n;

// 区间查询：查询区间 [l, r] 的和
int query_range_sum(int node, int start, int end, int l, int r) {
    apply_lazy(node, start, end);
    if (start > r || end < l) return 0;
    if (start >= l && end <= r) return tree[node];
    int mid = (start + end) / 2;
    int left_sum = query_range_sum(2 * node + 1, start, mid, l, r);
    int right_sum = query_range_sum(2 * node + 2, mid + 1, end, l, r);
    return left_sum + right_sum;
}

// 区间查询：查询区间 [l, r] 的最大值
int query_range_max(int node, int start, int end, int l, int r) {
    apply_lazy(node, start, end);
    if (start > r || end < l) return INT_MIN;//越界
    if (start >= l && end <= r) return max_tree[node];//查询区间覆盖当前区间直接返回当前节点
    int mid = (start + end) / 2;
    int left_max = query_range_max(2 * node + 1, start, mid, l, r);//左子区间最值
    int right_max = query_range_max(2 * node + 2, mid + 1, end, l, r);//右子区间最值
    return max(left_max, right_max);
}

// 区间查询：查询区间 [l, r] 的最小值
int query_range_min(int node, int start, int end, int l, int r) {
    apply_lazy(node, start, end);
    if (start > r || end < l) return INT_MAX;
    if (start >= l && end <= r) return min_tree[node];
    int mid = (start + end) / 2;
    int left_min = query_range_min(2 * node + 1, start, mid, l, r);
    int right_min = query_range_min(2 * node + 2, mid + 1, end, l, r);
    return min(left_min, right_min);
}
