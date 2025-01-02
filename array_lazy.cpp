#include "array_lazy.h"
extern int tree[4 * MAXN];
extern int max_tree[4 * MAXN];
extern int min_tree[4 * MAXN];
extern int lazy_add[4 * MAXN];
extern int mul_tree[4 * MAXN];
extern int lazy_mul[4 * MAXN];
extern int arr[MAXN];
extern int n;

// ����������
void apply_lazy(int node, int start, int end) {
    // �ȴ���˷�������
    if (lazy_mul[node] != 1) {
        tree[node] *= lazy_mul[node];
        max_tree[node] *= lazy_mul[node];
        min_tree[node] *= lazy_mul[node];
        mul_tree[node] *= lazy_mul[node];

        if (start != end) {
            lazy_mul[2 * node + 1] *= lazy_mul[node]; // ���˷���Ǵ��ݸ��ӽڵ�
            lazy_mul[2 * node + 2] *= lazy_mul[node];
        }
        lazy_mul[node] = 1; // ���ó˷�������Ϊ1
    }

    // ����ӷ�������
    if (lazy_add[node] != 0) {
        tree[node] += lazy_add[node] * (end - start + 1);
        max_tree[node] += lazy_add[node];
        min_tree[node] += lazy_add[node];
        mul_tree[node] += lazy_add[node] * (end - start + 1);

        if (start != end) {
            lazy_add[2 * node + 1] += lazy_add[node]; // ���ӷ���Ǵ��ݸ��ӽڵ�
            lazy_add[2 * node + 2] += lazy_add[node];
        }
        lazy_add[node] = 0; // ���üӷ�������Ϊ0
    }
}
