#include <cstdio>
#include <malloc.h>


typedef struct node {
    int data;
    struct node *Lson, *Rson;
} Bnode, *Bptr;

Bptr creat();

void preorder(Bptr p);//先序遍历
void inorder(Bptr p);//中序遍历
void postorder(Bptr p);//后序遍历

int main() {
    Bptr root = nullptr;
    root = creat();
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    return 0;
}

/* 请在这里填写答案 */
Bptr creat() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    Bnode *p1 = (Bnode *) malloc(sizeof(Bnode));;
    Bnode *p2 = (Bnode *) malloc(sizeof(Bnode));
    Bnode *p3 = (Bnode *) malloc(sizeof(Bnode));
    p1->data = a;
    p2->data = b;
    p2->Lson = p2->Rson = NULL;
    p3->data = c;
    p3->Lson = p3->Rson = NULL;
    p1->Lson = p2;
    p1->Rson = p3;
    return p1;
}

void preorder(Bptr p) {
    if (p != NULL) {
        printf("%d", p->data);
        preorder(p->Lson);
        preorder(p->Rson);
    }
}

void inorder(Bptr p) {
    if (p != NULL) {
        inorder(p->Lson);
        printf("%d", p->data);
        inorder(p->Rson);
    }
}

void postorder(Bptr p) {
    if (p != NULL) {
        postorder(p->Lson);
        postorder(p->Rson);
        printf("%d", p->data);
    }
}