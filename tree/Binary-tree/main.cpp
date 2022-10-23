#include <iostream>

#define ElemType char
#define MaxSize 100
using namespace std;
typedef struct node {
    ElemType data;
    struct node *lchild, *rchild;
} BTNode;

//创建二叉树
void CreateBTree(BTNode *&b, const char *str) {
    BTNode *st[MaxSize], *p;
    int top = -1, k, j = 0;
    char ch;
    b = nullptr;
    ch = str[j];
    while (ch == '\0') {
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

//销毁二叉树
void DestroyBTree(BTNode *&b) {
    if (b != nullptr) {
        DestroyBTree(b->lchild);
        DestroyBTree(b->rchild);
        free(b);
    }
}

// 查找结点
BTNode *FindNode(BTNode *b, ElemType x) {
    BTNode *p;
    if (b == nullptr) return nullptr;
    else if (b->data == x) return b;
    else {
        p = FindNode(b->lchild, x);
        if (p != nullptr) return p;
        else return FindNode(b->rchild, x);
    }
}

//找左孩子结点
BTNode *LchildNode(BTNode *p) {
    return p->lchild;
}

////找右孩子结点
BTNode *RchildNode(BTNode *p) {
    return p->rchild;
}

//求高度
int BTHeight(BTNode *b) {
    int lchildh, rchildh;
    if (b == nullptr) return 0;
    else {
        lchildh = BTHeight(b->lchild);
        rchildh = BTHeight(b->rchild);
        return (lchildh > rchildh) ? (lchildh + 1) : (rchildh + 1);
    }
}

//输出二叉树
void DispBtree(BTNode *b) {
    if (b != nullptr) {
        cout << b->data;
        if (b->lchild != nullptr || b->rchild != nullptr) {
            cout << "(";
            DispBtree(b->lchild);
            if (b->rchild != nullptr) cout << ",";
            DispBtree(b->rchild);
            cout << ")";
        }
    }
}

int main() {
    BTNode *b;
    CreateBTree(b, "A(B(D(,G)),G)),C(E,F))");

    DispBtree(b);
    return 0;
}
