#include "array_lazy.h"
extern int tree[4 * MAXN];
extern int max_tree[4 * MAXN];
extern int min_tree[4 * MAXN];
extern int lazy_add[4 * MAXN];
extern int mul_tree[4 * MAXN];
extern int lazy_mul[4 * MAXN];
extern int arr[MAXN];
extern int n;

// 处理懒惰标记
void apply_lazy(int node, int start, int end) {
    // 先处理乘法懒惰标记
    if (lazy_mul[node] != 1) {
        tree[node] *= lazy_mul[node];
        max_tree[node] *= lazy_mul[node];
        min_tree[node] *= lazy_mul[node];
        mul_tree[node] *= lazy_mul[node];

        if (start != end) {
            lazy_mul[2 * node + 1] *= lazy_mul[node]; // 将乘法标记传递给子节点
            lazy_mul[2 * node + 2] *= lazy_mul[node];
        }
        lazy_mul[node] = 1; // 重置乘法懒惰标记为1
    }

    // 处理加法懒惰标记
    if (lazy_add[node] != 0) {
        tree[node] += lazy_add[node] * (end - start + 1);
        max_tree[node] += lazy_add[node];
        min_tree[node] += lazy_add[node];
        mul_tree[node] += lazy_add[node] * (end - start + 1);

        if (start != end) {
            lazy_add[2 * node + 1] += lazy_add[node]; // 将加法标记传递给子节点
            lazy_add[2 * node + 2] += lazy_add[node];
        }
        lazy_add[node] = 0; // 重置加法懒惰标记为0
    }
}
