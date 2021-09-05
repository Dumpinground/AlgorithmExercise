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

int postfixCompute(int a, int b, char op) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        default:
            return 0;
    }
}

bool isNumber(char c) {
    return '0' <= c && c <= '9';
}

bool isNumber(int c) {
    return '0' <= c && c <= '9';
}

int numberAttach(int a, int b) {
    return a * 10 + b;
}

int postfixResult(char postfix[]) {
    SqStack S;
    InitStack(S);
    int r = 0;
    bool temp = false;
    for (int i = 0; i < strlen(postfix); i++) {
        char p = postfix[i];

        if (isNumber(p)) {
            temp = true;
            r = numberAttach(r, p - '0');
        } else {
            if (temp) {
                Push(S, r);
                temp = false;
            } else if (p == '+' || p == '-' || p == '*' || p == '/'){
                int a, b;
                Pop(S, b);
                Pop(S, a);
                r = postfixCompute(a, b, p);
                Push(S, r);
            }
            r = 0;
        }
    }
    return S.data[S.top];
}

int prefixResult(vector<string> prefix) {
    SqStack S;
    InitStack(S);
    int r;
    for (int i = prefix.size() - 1; i >= 0; i--) {
        switch (prefix[i][0]) {
            case '+':
            case '-':
            case '*':
            case '/':
                int a, b;
                Pop(S, a);
                Pop(S, b);
                r = postfixCompute(a, b, prefix[i][0]);
                Push(S, r);
                break;
            default:
                Push(S, atoi(prefix[i].data()));
        }
    }
    GetTop(S, r);
    return r;
}

TEST(Stack, testExpression) {
    int a[] = {'+', '-', '*', '/', '1', '2'};
//    vector<string> postfix = {"15", "7", "1", "1", "+", "-", "/", "3", "*", "2", "1", "1", "+", "+", "-"};
    char postfix[] = "15 7 1 1 + - / 3 * 2 1 1 + + -";
    cout << postfixResult(postfix) << endl;
    vector<string> prefix = {"-", "*", "/", "15", "-", "7", "+", "1", "1", "3", "+", "2", "+", "1", "1"};
    cout << prefixResult(prefix) << endl;
}

int infxCompute(SqStack &S, SqStack &Sop) {
    int a, b, op;
    Pop(S, b);
    Pop(S, a);
    Pop(Sop, op);
    switch (op) {
        case '+':
            a = a + b;
        case '-':
            a = a - b;
        case '*':
            a = a * b;
        case '/':
            a = a / b;
    }
    return a;
}

ElemType popUntil(SqStack &S, ElemType e) {
    int x;
    while (S.data[S.top] != e) {
        Pop(S, x);
    }
    Pop(S, x);
    return x;
}

int infixResultWithBracket(char infix[]) {
    int x;
    SqStack S, Sop;
    InitStack(S);
    InitStack(Sop);
    for (int i = 0; i < strlen(infix); ++i) {
        int c = infix[i];
        switch (c) {
            case '+':
            case '-':
            case '*':
            case '/':
                Push(Sop, c);
                break;
            case '(':
            case '[':
            case '{':
                Push(S, c);
                break;
            case ')':
                popUntil(S, '(');
                break;
            case ']':
                popUntil(S, '[');
                break;
            case '}':
                popUntil(S, '{');
                break;
            default:
//                if (c >= '0' && c <= '9')
                c = c - '0';
                Push(S, c);
        }
    }
    return S.data[S.top];
}

void intPrint(char c[]) {
    for (int i = 0; i < strlen(c); ++i) {
        cout << c[i] << " " << int(c[i]) << "  ";
    }
    cout << endl;
}

TEST(Stack, testExpression2) {
    char infix[] = "((15/(7-(1+1)))*3)-(2+(1+1))";
    cout << int(' ') << endl;
    char op[] = "+-*/";
    char numbers[] = "0123456789";
    char bracket[] = "()[]{}";
    intPrint(op);
    intPrint(numbers);
    intPrint(bracket);
    cout << char(92) << " " << 92 << "  " << char(124) << " " << 124 << endl;
    cout << '\0' << "\\0" << endl;
}