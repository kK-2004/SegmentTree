#include "ui.h"


int tree[4 * MAXN];     // 线段树数组（区间和）
int max_tree[4 * MAXN]; // 线段树数组（区间最大值）
int min_tree[4 * MAXN]; // 线段树数组（区间最小值）
int lazy_add[4 * MAXN];     // 懒惰标记数组
int mul_tree[4 * MAXN]; // 线段树数组（区间乘积）
int lazy_mul[4 * MAXN]; // 懒惰标记数组（乘法更新）
int arr[MAXN];          // 输入的原始数组
int n;                  // 数组大小

// 构建线段树
void build(int node, int start, int end) {
    lazy_add[node] = 0;  // 初始化加法懒惰标记为0
    lazy_mul[node] = 1;  // 初始化乘法懒惰标记为1（乘法单位元）
    if (start == end) {
        tree[node] = max_tree[node] = min_tree[node] = arr[start];
        mul_tree[node] = arr[start]; // 乘积初始化为该位置的值
    }
    else {
        int mid = (start + end) / 2;
        build(2 * node + 1, start, mid);
        build(2 * node + 2, mid + 1, end);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        max_tree[node] = max(max_tree[2 * node + 1], max_tree[2 * node + 2]);
        min_tree[node] = min(min_tree[2 * node + 1], min_tree[2 * node + 2]);
        mul_tree[node] = mul_tree[2 * node + 1] * mul_tree[2 * node + 2]; // 初始化乘积
    }
}

// 打印当前数组状态
void print_array() {
    cout << "\n当前数组状态：[ ";
    for (int i = 0; i < n; ++i) {
        cout << query_range_sum(0, 0, n - 1, i, i) << " ";
    }
    cout << "]" << endl;
}

void wait_and_clear() {
    cout << "\n按回车键继续..." << endl;
    cin.ignore(); // 清空输入缓冲区，避免多余字符影响
    cin.get();    // 等待用户按下回车键
    system("cls"); // 清屏
}

bool is_valid_range(int l, int r, int n) {
    return l >= 1 && r <= n && l <= r;
}



void interactiveInterface() {
    printf("请输入数组长度：");
    while (scanf_s("%d", &n) != 1 || n <= 0) {
        printf("输入无效，请输入一个有效的整数：");
        while (getchar() != '\n'); // 清空输入缓冲区
    }

    printf("请输入数组元素：");
    for (int i = 0; i < n; ++i) {
        while (scanf_s("%d", &arr[i]) != 1) {
            printf("输入无效，请重新输入第 %d 个元素：", i + 1);
            while (getchar() != '\n'); // 清空输入缓冲区
        }
    }

    // 构建线段树
    build(0, 0, n - 1);

    while (1) {
        print_array(); // 在菜单上方打印数组内容
        printf("\n--- 线段树操作菜单 ---\n");
        printf("1. 区间加法更新\n");
        printf("2. 区间乘法更新\n");
        printf("3. 查询区间和\n");
        printf("4. 查询区间最大值\n");
        printf("5. 查询区间最小值\n");
        printf("6. 单点更新\n");
        printf("7. 退出\n");
        printf("请输入操作选择：");

        int choice;
        while (scanf_s("%d", &choice) != 1 || choice < 1 || choice > 7) {
            printf("无效选择，请输入一个有效的操作号 (1-7)：");
            while (getchar() != '\n'); // 清空输入缓冲区
        }

        if (choice == 1) {
            int l, r, val;
            printf("请输入区间 [l, r] 和加法值：");
            while (scanf_s("%d %d %d", &l, &r, &val) != 3 || !is_valid_range(l, r, n)) {
                printf("无效区间或输入错误，请重新输入 [l, r] 和加法值：");
                while (getchar() != '\n'); // 清空输入缓冲区
            }
            update_range_add(0, 0, n - 1, l - 1, r - 1, val);
        }
        else if (choice == 2) {
            int l, r, val;
            printf("请输入区间 [l, r] 和乘法值：");
            while (scanf_s("%d %d %d", &l, &r, &val) != 3 || !is_valid_range(l, r, n)) {
                printf("无效区间或输入错误，请重新输入 [l, r] 和乘法值：");
                while (getchar() != '\n'); // 清空输入缓冲区
            }
            update_range_mul(0, 0, n - 1, l - 1, r - 1, val);
        }
        else if (choice == 3) {
            int l, r;
            printf("请输入区间 [l, r]：");
            while (scanf_s("%d %d", &l, &r) != 2 || !is_valid_range(l, r, n)) {
                printf("无效区间，请重新输入 [l, r]：");
                while (getchar() != '\n'); // 清空输入缓冲区
            }
            printf("区间和: %d\n",query_range_sum(0, 0, n - 1, l - 1, r - 1));
        }
        else if (choice == 4) {
            int l, r;
            printf("请输入区间 [l, r]：");
            while (scanf_s("%d %d", &l, &r) != 2 || !is_valid_range(l, r, n)) {
                printf("无效区间，请重新输入 [l, r]：");
                while (getchar() != '\n'); // 清空输入缓冲区
            }
            printf("区间最大值: %d\n", query_range_max(0, 0, n - 1, l - 1, r - 1));
        }
        else if (choice == 5) {
            int l, r;
            printf("请输入区间 [l, r]：");
            while (scanf_s("%d %d", &l, &r) != 2 || !is_valid_range(l, r, n)) {
                printf("无效区间，请重新输入 [l, r]：");
                while (getchar() != '\n'); // 清空输入缓冲区
            }
            printf("区间最小值: %d\n", query_range_min(0, 0, n - 1, l - 1, r - 1));
        }
        else if (choice == 6) {
            printf("请输入更新位置和更新数值：");
            int index, val;
            while (scanf_s("%d %d", &index, &val) != 2 || !is_valid_range(index, index, n)) {
                printf("无效区间，请重新输入位置：");
                while (getchar() != '\n'); // 清空输入缓冲区
            }
            update_point(0, 0, n - 1, index-1, val);

        }

        else if (choice == 7) {
            break;
        }

        wait_and_clear(); // 等待用户按回车键并清屏
    }
}