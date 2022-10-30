#include <stdio.h>
#include <malloc.h>

#define MaxSize 100
typedef char ElemType;
typedef struct node {
    ElemType data;                //数据元素
    struct node *lchild;        //指向左孩子
    struct node *rchild;        //指向右孩子
} BTNode;

void CreateBTNodePre(BTNode *&b, char *str); //根据括号表示法的str，创建二叉树b，并先序输出二叉树。

int main() {
    BTNode *b;
    char str[100];
    scanf("%s", str);
    CreateBTNodePre(b, str);  //括号表示法创建二叉树 ,并先序输出二叉树。
    return 0;
}

void CreateBTNodePre(BTNode *&b, char *str) {      //由str串创建二叉树，并先序输出二叉树。
    BTNode *st[MaxSize], *p;
    int top = -1, k, j = 0;
    char ch;
    b = nullptr;
    ch = str[j];
    while (ch != '\0') {
        switch (ch) {
            case '(':
                top++;
                st[top] = p;
                k = 1;
                break;
            case ')':
                top--;
                break;
            case ',':
                k = 2;
                break;
            default:
                p = (BTNode *) malloc(sizeof(BTNode));
                p->data = ch;
                p->lchild = p->rchild = nullptr;
                if (b == nullptr) {
                    b = p;
                } else {
                    switch (k) {
                        case 1:
                            st[top]->lchild = p;
                            break;
                        case 2:
                            st[top]->rchild = p;
                            break;
                    }
                }
        }
        j++;
        ch = str[j];
    }

}