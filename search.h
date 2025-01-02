#pragma once
#include "headers.h"
#include "array_lazy.h"
// 区间查询：查询区间 [l, r] 的和
int query_range_sum(int node, int start, int end, int l, int r);
// 区间查询：查询区间 [l, r] 的最大值
int query_range_max(int node, int start, int end, int l, int r);
// 区间查询：查询区间 [l, r] 的最小值
int query_range_min(int node, int start, int end, int l, int r);