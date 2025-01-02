#pragma once
#include "headers.h"
#include "add.h"
#include "multiply.h"
#include "search.h"
#include "updatePoint.h"
void build(int node, int start, int end);
// 打印当前数组状态
void print_array();
// 清屏函数
void wait_and_clear();
bool is_valid_range(int l, int r, int n);
void interactiveInterface();