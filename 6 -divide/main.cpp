#include <iostream>
#include "linklist.h"
#include <cstring>

void Sqlit1(LinkNode *&L) {
    LinkNode *pre, *p, *q;
    if (L->next == nullptr || L->next->next == nullptr) {
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
    printf("解法一");
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
//        $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//        $$                                _.ooOoo._                               $$
//        $$                               o888888888o                              $$
//        $$                               88"  .  "88                              $$
//        $$                               (|  ^_^  |)                              $$
//        $$                               O\   =   /O                              $$
//        $$                            ____/`-----'\____                           $$
//        $$                          .'  \\|       |$$  `.                         $$
//        $$                         /  \\|||   :   |||$$  \                        $$
//        $$                        /  _|||||  -:-  |||||-  \                       $$
//        $$                        |   | \\\   -   $$/ |   |                       $$
//        $$                        | \_|  ''\-----/''  |   |                       $$
//        $$                        \  .-\___  `-`  ____/-. /                       $$
//        $$                      ___`. .'   /--.--\   `. . ___                     $$
//        $$                    ."" '<  `.____\_<|>_/____.'  >'"".                  $$
//        $$                  | | :  `- \`.;`.\ _ /``;.`/ - ` : | |                 $$
//        $$                  \  \ `-.   \_ ___\ /___ _/   .-` /  /                 $$
//        $$            ========`-.____`-.____\_____/____.-`____.-'========         $$
//        $$                                  `=---='                               $$
//        $$            ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^        $$
//        $$                  佛祖保佑          永无BUG         永不修改               $$
//        $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//                      Spring Boot:  (v2.3.0.RELEASE)