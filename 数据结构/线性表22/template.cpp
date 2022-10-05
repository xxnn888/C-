#include <iostream>
#include "Linklist.h"
#include <string>
#include <cstring>

void Sqlit1(LinkNode *&L) {
    LinkNode *pre, *p, *q;
    if (L->next == NULL || L->next->next == NULL) {
        return;
    }
    int x;
    x = L->next->data;
    pre = L->next;
    p = pre->next;
    while (p != NULL) {
        if (p->data < x) {
            pre->next = p->next;
            p->next = L->next;
            L->next = p;
            p = pre->next;
        } else {
            pre = p;
            p = pre->next;
        }
    }

}

int main() {
    LinkNode *L;
    ElemType a[] = "daxgdchaeb";
    int n = strlen(a);
    printf("解法一\n");
    CreateListR(L, a, n);
    printf("L:");
    DispList(L);
    printf("案首节点划分\n");
    Sqlit1(L);
    printf("L:");
    DispList(L);
    DestroyList(L);
    return 0;
}
