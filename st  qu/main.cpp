#include <iostream>
#include "Stack.h"

using namespace std;

int main() {
    SqStack *S;
    int e = 0;
    InitStack(S);
    for (int i = 0; i < 10; ++i) {
        Push(S, i);
    }
    PrintStack(S);
    Pop(S, e);
    cout << endl;
    PrintStack(S);
    return 0;
}
