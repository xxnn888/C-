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

//二叉树的先序遍历递归算法
void PreOrder(BTNode *b) {
    if (b != NULL) {
        printf("%d", b->data);
        PreOrder(b->lchild);
        PreOrder(b->rchild);
    }
}

//二叉树先序遍历非递归算法
void PreOrder1(BTNode *b) {
    BTNode *St[MaxSize], *p;
    int top = -1;
    if (b != NULL) {
        top++;
        St[top] = b;
        while (top > -1) {
            p = St[top];
            top--;
            printf("%c", p->data);
            if (p->rchild != NULL) {
                top++;
                St[top] = p->rchild;
            }
            if (p->lchild != NULL) {
                top++;
                St[top] = p->lchild;
            }
        }
        printf("\n");
    }
};

//二叉树的中序遍历递归算法
void InOrder(BTNode *b) {
    if (b != NULL) {
        PreOrder(b->lchild);
        printf("%d", b->data);
        PreOrder(b->rchild);
    }
};

//二叉树中序遍历非递归算法
void InOrder1(BTNode *b) {
    BTNode *St[MaxSize], *p;
    int top = -1;
    if (b != NULL) {
        p = b;
        while (top > -1 || p != NULL) {
            while (p != NULL) {
                top++;
                St[top] = p;
                p = p->lchild;
            }
            if (top > -1) {
                p = St[top];
                top--;
                printf("%c", p->data);
            }
        }
        printf("\n");
    }
};

//二叉树的后序遍历递归算法
void PostOrder(BTNode *b) {
    if (b != NULL) {
        PreOrder(b->lchild);
        PreOrder(b->rchild);
        printf("%d", b->data);

    }
};

//二叉树后序遍历非递归算法
void PostOrder1(BTNode *b) {
    BTNode *St[MaxSize];
    BTNode *p;
    int top = -1;
    bool flag;
    if (b != NULL) {
        do {
            while (b != NULL) {
                top++;
                St[top] = b;
                b = b->lchild;
            }
            p = NULL;
            flag = true;
            while (top != -1 && flag) {
                b = St[top];
                if (b->rchild == p) {
                    printf("%c ", b->data);
                    top--;
                    p = b;
                } else {
                    b = b->rchild;
                    flag = false;
                }
            }
        } while (top != -1);
        printf("\n");
    }
}

void TraveLevel(BTNode *b) {
    BTNode *Qu[MaxSize];
    int front, rear;
    front = rear = 0;
}

int main() {
    BTNode *b;
    CreateBTree(b, "A(B(D(,G)),G)),C(E,F))");
    DispBtree(b);
    return 0;
}
