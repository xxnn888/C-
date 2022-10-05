/**
 * 头插法建立单链表
 */
#include <cstdio>
#include <cstdlib>

typedef char ElemType;

typedef struct LNode {
    ElemType data;
    struct LNode *next;        //指向后继结点
} LinkNode;                     //单链表结点类型

void CreateListF(LinkNode *&L, ElemType a[], int n) {
    LinkNode *s;
    L = (LinkNode *) malloc(sizeof(LinkNode));
    L->next = NULL;
    for (int i = 0; i < n; ++i) {
        s = (LinkNode *) malloc(sizeof(LinkNode));
        s->data = a[i];
        s->next = L->next;
        L->next = s;
    }

}

/**
 * 尾插法建立单链表
 */
void CreateListR(LinkNode *&L, ElemType a[], int n) {
    LinkNode *s, *r;
    L = (LinkNode *) malloc(sizeof(LinkNode));
    L->next = nullptr;
    r = L;
    for (int i = 0; i < n; ++i) {
        s = (LinkNode *) malloc(sizeof(LinkNode));
        s->data = a[i];
        r->next = s;
        r = s;
    }
    r->next = nullptr;

}

/**
 * 初始化线性表
 */
void InitList(LinkNode *&L) {
    L = (LinkNode *) malloc(sizeof(LinkNode));
    L->next = nullptr;
}

/**
 * 销毁线性表
 */
void DestroyList(LinkNode *&L) {
    LinkNode *pre = L, *p = pre->next;
    while (p != nullptr) {
        free(pre);
        pre = p;
        p = pre->next;
    }
    delete pre;
}

/**
 * 判线性表是否为空表。空表返回true，否则返回false。
 */
bool ListEmpty(LinkNode *L) {
    return L->next == nullptr;
}

/**
 * 求线性表的长度
 */
int ListLength(LinkNode *L) {
    int n = 0;
    LinkNode *p = L;
    while (p->next != nullptr) {
        n++;
        p = p->next;
    }
    return n;
}

/**
 * 输出线性表: 每个数据后面一个空格
 */
void DispList(LinkNode *L) {
    LinkNode *p = L->next;
    while (p != nullptr) {
        printf("%c ", p->data);
        p = p->next;
    }
    printf("\n");
}

/**
 * 求线性表中第i个元素值。
 * 存在第i个数据结点,其值存入e,然后返回true。
 * 不存在第i个数据结点,返回false。
 */
bool GetElem(LinkNode *L, int i, ElemType &e) {
    int j = 0;
    LinkNode *p = L;
    while (p != nullptr && j < i) {
        j++;
        p = p->next;
    }
    if (p == nullptr) return false;
    else {
        e = p->data;
        return true;
    }
}

/**
 * 查找第一个值域为e的元素序号。
 * 若存在，返回其逻辑序号；若不存在，返回0。
 */
int LocateElem(LinkNode *L, ElemType e) {
    LinkNode *p = L->next;
    int n = 1;
    while (p != nullptr && p->data != e) {
        p = p->next;
        n++;
    }
    if (p == nullptr) return 0;
    else return n;
}

/**
 * 插入第i个元素。
 * 插入成功，返回true；插入不成功，返回false。
 */
bool ListInsert(LinkNode *&L, int i, ElemType e) {
    LinkNode *p = L, *s;
    int n = 0;
    while (p != nullptr && n < i - 1) {
        n++;
        p = p->next;
    }
    if (p == nullptr) return false;
    else {
        s = (LinkNode *) malloc(sizeof(LinkNode));
        s->data = e;
        s->next = p->next;
        p->next = s;
        return true;
    }
}

/**
 * 删除第i个元素。
 * 如果第i个元素存在，其值存入e，返回true；
 * 如果第i个元素不存在，返回false。
 */
bool ListDelete(LinkNode *&L, int i, ElemType &e) {
    LinkNode *p = L, *pre;
    int n = 0;
    while (p != nullptr && n < i - 1) {
        n++;
        p = p->next;
    }
    if (p == nullptr) return false;
    else {
        pre = p->next;
        if (pre == nullptr) {
            return false;
        } else {
            e = pre->data;
            p->next = pre->next;
            free(pre);
            return true;
        }
    }
}
