//
// Created by hasee on 2021/9/3.
//

#include <gtest/gtest.h>

//#include "../myLib/stack/char ver/stack.h"
#include "../myLib/stack/stack.h"
#include "../myLib/queue/Queue.h"

using namespace std;

bool bracketCheck(char str[]) {
    SqStack S;
    InitStack(S);
    ElemType output;
    for (int i = 0; i < strlen(str); ++i) {
        switch (str[i]) {
            case '{':
            case '[':
            case '(':
                Push(S, str[i]);
                break;
            case '}':
                Pop(S, output);
                if (output != '{')
                    return false;
                break;
            case ']':
                Pop(S, output);
                if (output != '[')
                    return false;
                break;
            case ')':
                Pop(S, output);
                if (output != '(')
                    return false;
        }
    }
    if (!StackEmpty(S))
        return false;
    return true;
}

TEST(Stack, testLIFO) {
    string a = "{(())[]}";
    cout << bracketCheck(a.data()) << endl;
}