#include <iostream>
#include "Linklist.h"

int main() {
    ElemType a[] = "9345761";
    printf("%s\n", a);
    LinkNode *l1;
    int n = 7;
    CreateListR(l1, a, n);
    nizhi(l1, a, n);
    DispList(l1);
    sort1(l1, a, n);
    DispList(l1);
    return 0;
}
