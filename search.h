#pragma once
#include "headers.h"
#include "array_lazy.h"
// �����ѯ����ѯ���� [l, r] �ĺ�
int query_range_sum(int node, int start, int end, int l, int r);
// �����ѯ����ѯ���� [l, r] �����ֵ
int query_range_max(int node, int start, int end, int l, int r);
// �����ѯ����ѯ���� [l, r] ����Сֵ
int query_range_min(int node, int start, int end, int l, int r);