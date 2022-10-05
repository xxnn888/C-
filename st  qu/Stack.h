//
// Created by 15218 on 2022/9/28.
//

#ifndef ST__QU_STACK_H
#define ST__QU_STACK_H
#define MaxSize 50
typedef int ElemType;

typedef struct {
    ElemType data[MaxSize];        //存放顺序表元素
    int top;            //存放顺序表的长度
} SqStack;

//初始化栈
void InitStack(SqStack *&s) {
    s = new SqStack;
    s->top = -1;
}

//销毁栈
void DestroyStack(SqStack *&s) {
    delete (s);
}

//判断栈是否为空
bool StackEmpty(SqStack *&s) {
    return s->top == -1;
}

//进栈
bool Push(SqStack *&s, ElemType e) {
    if (s->top == MaxSize - 1) return false;
    else {
        s->top++;
        s->data[s->top] = e;
        return true;
    }
}

//出栈
bool Pop(SqStack *&s, ElemType &e) {
    if (s->top == -1) {
        return false;
    }
    e = s->data[s->top];
    s->top--;
    return true;
}

//输出栈
void PrintStack(SqStack *s) {
    SqStack L;
    L = *s;
    if (L.top == -1) {
        return;
    }
    while (L.top != -1) {
        std::cout << L.data[L.top] << " ";
        L.top--;
    }

}

//取栈顶元素
bool GetTop(SqStack *&s, ElemType &e) {
    if (s->top == -1) return false;
    e = s->data[s->top];
    return true;
}

bool
#endif //ST__QU_STACK_H
