#pragma once
#include "headers.h"
#include "array_lazy.h"
// 区间更新：将区间 [l, r] 乘以 val（乘法更新）
void update_range_mul(int node, int start, int end, int l, int r, int val);