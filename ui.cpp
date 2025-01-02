#include "ui.h"


int tree[4 * MAXN];     // �߶������飨����ͣ�
int max_tree[4 * MAXN]; // �߶������飨�������ֵ��
int min_tree[4 * MAXN]; // �߶������飨������Сֵ��
int lazy_add[4 * MAXN];     // ����������
int mul_tree[4 * MAXN]; // �߶������飨����˻���
int lazy_mul[4 * MAXN]; // ���������飨�˷����£�
int arr[MAXN];          // �����ԭʼ����
int n;                  // �����С

// �����߶���
void build(int node, int start, int end) {
    lazy_add[node] = 0;  // ��ʼ���ӷ�������Ϊ0
    lazy_mul[node] = 1;  // ��ʼ���˷�������Ϊ1���˷���λԪ��
    if (start == end) {
        tree[node] = max_tree[node] = min_tree[node] = arr[start];
        mul_tree[node] = arr[start]; // �˻���ʼ��Ϊ��λ�õ�ֵ
    }
    else {
        int mid = (start + end) / 2;
        build(2 * node + 1, start, mid);
        build(2 * node + 2, mid + 1, end);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        max_tree[node] = max(max_tree[2 * node + 1], max_tree[2 * node + 2]);
        min_tree[node] = min(min_tree[2 * node + 1], min_tree[2 * node + 2]);
        mul_tree[node] = mul_tree[2 * node + 1] * mul_tree[2 * node + 2]; // ��ʼ���˻�
    }
}

// ��ӡ��ǰ����״̬
void print_array() {
    cout << "\n��ǰ����״̬��[ ";
    for (int i = 0; i < n; ++i) {
        cout << query_range_sum(0, 0, n - 1, i, i) << " ";
    }
    cout << "]" << endl;
}

void wait_and_clear() {
    cout << "\n���س�������..." << endl;
    cin.ignore(); // ������뻺��������������ַ�Ӱ��
    cin.get();    // �ȴ��û����»س���
    system("cls"); // ����
}

bool is_valid_range(int l, int r, int n) {
    return l >= 1 && r <= n && l <= r;
}



void interactiveInterface() {
    printf("���������鳤�ȣ�");
    while (scanf_s("%d", &n) != 1 || n <= 0) {
        printf("������Ч��������һ����Ч��������");
        while (getchar() != '\n'); // ������뻺����
    }

    printf("����������Ԫ�أ�");
    for (int i = 0; i < n; ++i) {
        while (scanf_s("%d", &arr[i]) != 1) {
            printf("������Ч������������� %d ��Ԫ�أ�", i + 1);
            while (getchar() != '\n'); // ������뻺����
        }
    }

    // �����߶���
    build(0, 0, n - 1);

    while (1) {
        print_array(); // �ڲ˵��Ϸ���ӡ��������
        printf("\n--- �߶��������˵� ---\n");
        printf("1. ����ӷ�����\n");
        printf("2. ����˷�����\n");
        printf("3. ��ѯ�����\n");
        printf("4. ��ѯ�������ֵ\n");
        printf("5. ��ѯ������Сֵ\n");
        printf("6. �������\n");
        printf("7. �˳�\n");
        printf("���������ѡ��");

        int choice;
        while (scanf_s("%d", &choice) != 1 || choice < 1 || choice > 7) {
            printf("��Чѡ��������һ����Ч�Ĳ����� (1-7)��");
            while (getchar() != '\n'); // ������뻺����
        }

        if (choice == 1) {
            int l, r, val;
            printf("���������� [l, r] �ͼӷ�ֵ��");
            while (scanf_s("%d %d %d", &l, &r, &val) != 3 || !is_valid_range(l, r, n)) {
                printf("��Ч���������������������� [l, r] �ͼӷ�ֵ��");
                while (getchar() != '\n'); // ������뻺����
            }
            update_range_add(0, 0, n - 1, l - 1, r - 1, val);
        }
        else if (choice == 2) {
            int l, r, val;
            printf("���������� [l, r] �ͳ˷�ֵ��");
            while (scanf_s("%d %d %d", &l, &r, &val) != 3 || !is_valid_range(l, r, n)) {
                printf("��Ч���������������������� [l, r] �ͳ˷�ֵ��");
                while (getchar() != '\n'); // ������뻺����
            }
            update_range_mul(0, 0, n - 1, l - 1, r - 1, val);
        }
        else if (choice == 3) {
            int l, r;
            printf("���������� [l, r]��");
            while (scanf_s("%d %d", &l, &r) != 2 || !is_valid_range(l, r, n)) {
                printf("��Ч���䣬���������� [l, r]��");
                while (getchar() != '\n'); // ������뻺����
            }
            printf("�����: %d\n",query_range_sum(0, 0, n - 1, l - 1, r - 1));
        }
        else if (choice == 4) {
            int l, r;
            printf("���������� [l, r]��");
            while (scanf_s("%d %d", &l, &r) != 2 || !is_valid_range(l, r, n)) {
                printf("��Ч���䣬���������� [l, r]��");
                while (getchar() != '\n'); // ������뻺����
            }
            printf("�������ֵ: %d\n", query_range_max(0, 0, n - 1, l - 1, r - 1));
        }
        else if (choice == 5) {
            int l, r;
            printf("���������� [l, r]��");
            while (scanf_s("%d %d", &l, &r) != 2 || !is_valid_range(l, r, n)) {
                printf("��Ч���䣬���������� [l, r]��");
                while (getchar() != '\n'); // ������뻺����
            }
            printf("������Сֵ: %d\n", query_range_min(0, 0, n - 1, l - 1, r - 1));
        }
        else if (choice == 6) {
            printf("���������λ�ú͸�����ֵ��");
            int index, val;
            while (scanf_s("%d %d", &index, &val) != 2 || !is_valid_range(index, index, n)) {
                printf("��Ч���䣬����������λ�ã�");
                while (getchar() != '\n'); // ������뻺����
            }
            update_point(0, 0, n - 1, index-1, val);

        }

        else if (choice == 7) {
            break;
        }

        wait_and_clear(); // �ȴ��û����س���������
    }
}