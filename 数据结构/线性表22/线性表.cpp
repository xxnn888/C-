#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50
typedef char ElemType;

typedef struct {
    ElemType data[MaxSize];        //存放顺序表元素
    int length;            //存放顺序表的长度
} SqList;                //声明顺序表的类型
void InitList(SqList *&L) {
    L = (SqList *) malloc(sizeof(SqList));
    L->length = 0;
}

/**
 * 释放顺序表L。
 */
void DestroyList(SqList *&L) {
    free(L);
}

/**
 * 判断顺序表L是否为空表。
 * 空表返回true，非空表返回false。
 */
bool ListEmpty(SqList *L) {
    return L->length == 0;
}

/**
 * 返回顺序表L的元素个数。
 */
int ListLength(SqList *L) {
    return L->length;
}

/**
 * 输出顺序表L。
 */
void DispList(SqList *L) {
    for (int i = 0; i < L->length; i++) {
        printf("%c ", L->data[i]);
    }
    printf("\n");
}

/**
 * 获取顺序表L中第i(1≤i≤L->length)个元素，将其值存入e，然后返回true；
 * 如果不能获取到第i个元素，返回false。
 */
bool GetElem(SqList *L, int i, ElemType &e) {
    if (i < 1 || i > L->length) return false;
    e = L->data[i - 1];
    return true;
}

/**
 * 在顺序表L中查找元素e。
 * 如果存在e，则返回e的逻辑序号，否则返回0。
 */
int LocateElem(SqList *L, ElemType e) {
    for (int i = 0; i < L->length; i++) {
        if (L->data[i] == e) return i + 1;
    }
    return 0;
}

/**
 * 在顺序表L中第ii(1≤i≤L->length)个位置上插入元素e。
 * 插入成功，返回true。插入不成功，返回false。
 */
bool ListInsert(SqList *&L, int i, ElemType e) {
    if (i < 1 || i > L->length + 1 || L->length == MaxSize)return false;
    i--;
    for (int j = L->length; j > i; j--) {
        L->data[j] = L->data[j - 1];
    }
    L->data[i] = e;
    L->length++;
    return true;
}

/**
 * 从顺序表L中删除第ii(1≤i≤L->length)个元素。
 * 删除成功，返回true。删除不成功，返回false。
 */
bool ListDelete(SqList *&L, int i, ElemType &e) {
    int j;
    if (i < 1 || i > L->length)return false;
    i--;
    e = L->data[i];
    for (j = i; j < L->length - 1; j++) {
        L->data[j] = L->data[j + 1];
    }
    L->length--;
    return true;
}

int main() {
    SqList *L;
    ElemType e;
    printf("顺序表的基本运算如下:\n");
    printf("  (1)初始化顺序表L\n");
    InitList(L);
    printf("  (2)依次插入a,b,c,d,e元素\n");
    ListInsert(L, 1, 'a');
    ListInsert(L, 2, 'b');
    ListInsert(L, 3, 'c');
    ListInsert(L, 4, 'd');
    ListInsert(L, 5, 'e');
    printf("  (3)输出顺序表L:");
    DispList(L);
    printf("  (4)顺序表L长度:%d\n", ListLength(L));
    printf("  (5)顺序表L为%s\n", (ListEmpty(L) ? "空" : "非空"));
    GetElem(L, 3, e);
    printf("  (6)顺序表L的第3个元素:%c\n", e);
    printf("  (7)元素a的位置:%d\n", LocateElem(L, 'a'));
    printf("  (8)在第4个元素位置上插入f元素\n");
    ListInsert(L, 4, 'f');
    printf("  (9)输出顺序表L:");
    DispList(L);
    printf("  (10)删除L的第3个元素\n");
    ListDelete(L, 3, e);
    printf("  (11)输出顺序表L:");
    DispList(L);
    printf("  (12)释放顺序表L\n");
    DestroyList(L);
    return 0;
}

/* 请在下面填写代码 */
