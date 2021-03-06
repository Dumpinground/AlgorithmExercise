//
// Created by hasee on 2021/9/3.
//

#include <gtest/gtest.h>

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

//TODO need fix
int infixResult(char infix[]) {
    int r = 0;
    bool temp = false;
    SqStack S, Sop;
    InitStack(S);
    InitStack(Sop);
    string postfix;
    for (int i = 0; i < strlen(infix); i++) {
        char c = infix[i];
        if (isNumber(c)) {
            r = numberAttach(r, c - '0');
            temp = true;
        } else {
            if (temp) {
                Push(S, r);
                temp = false;
            }
            if (c == '+' || c == '-' || c == '*' || c == '/') {
                int op, a, b;
                if (Pop(Sop, op)) {
                    if (c == '*' || c == '/') {
                        Pop(S, b);
                        Pop(S, a);
                        if (op == '+' || op == '-') {
                            Push(Sop, op);
                        } else {
                            r = postfixCompute(a, b, op);
                            Push(S, r);
                        }
                        Push(Sop, c);
                    } else {
                        Pop(S, b);
                        Pop(S, a);
                        r = postfixCompute(a, b, op);
                        Push(Sop, c);
                        Push(S, r);
                    }
                } else {
                    Push(Sop, c);
                }
            }
            r = 0;
        }
    }
    return GetTop(S);
}

string infixResultWithBracket(char infix[]) {
    string postfix = "";
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
    return postfix;
}

void intPrint(char c[]) {
    for (int i = 0; i < strlen(c); ++i) {
        cout << c[i] << " " << int(c[i]) << "  ";
    }
    cout << endl;
}

TEST(Stack, testExpression2) {
    char infix[] = "((15/(7-(1+1 )))*3)-(2+(1+1))";
//    cout << int(' ') << endl;
//    char op[] = "+-*/";
//    char numbers[] = "0123456789";
//    char bracket[] = "()[]{}";
//    intPrint(op);
//    intPrint(numbers);
//    intPrint(bracket);
//    cout << char(92) << " " << 92 << "  " << char(124) << " " << 124 << endl;
//    cout << '\0' << "\\0" << endl;

    char a[] = "2 + 4 * 12 - 6 / 2";
    cout << infixResult(a) << endl;
    cout << 29 << endl;
}

int factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

int Fib(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return Fib(n - 1) + Fib(n - 2);
}

TEST(Stack, testFactorial) {
    cout << factorial(10) << endl;
}

bool bracketMatch(char expression[]) {
    int i = 0, pop;
    SqStack S;
    InitStack(S);
    while (expression[i] != '\0') {
        char c = expression[i];
        switch (c) {
            case '(':
            case '[':
            case '{':
                Push(S, c);
                break;
            case ')':
                Pop(S, pop);
                if (pop != '(')
                    return false;
                break;
            case ']':
                Pop(S, pop);
                if (pop != '[')
                    return false;
                break;
            case '}':
                Pop(S, pop);
                if (pop != '{')
                    return false;
        }
        i++;
    }
    return StackEmpty(S);
}

TEST(StackApp, 1) {
    char expression[] = "1+(2-3)-[3/(2+4)]+{34-22/54+[32-56+(23+11)]}\0";
    cout << bracketMatch(expression) << endl;
}

char* carSchedule(char cars[]) {
    SqStack S;
    InitStack(S);
    int n = strlen(cars), s = 0;
    char c;
    for (int i = 0; i < n; ++i) {
        c = cars[i];
        if (c == 'H')
            Push(S, c);
        else {
            cars[s++] = c;
        }
    }
    while (!StackEmpty(S)) {
        ElemType e;
        int top = S.top;
        Pop(S, e);
        cars[n - 1 - top] = e;
    }
    return cars;
}

TEST(StackApp, 2) {
    char cars[] = "HSHHSSHSHSHHSHHHHHSSHSS";
    cout << carSchedule(cars) << endl;
}

struct PStack {
    int _n[30];
    int _val[30];
    int top;

    PStack() {
        top = -1;
    }

    bool push(int n, int val) {
        if (top + 1 == 30)
            return false;
        top++;
        _n[top] = n;
        _val[top] = val;
        return true;
    }

    bool pop(int &n, int &val) {
        if (top == -1)
            return false;
        top--;
        n = _n[top];
        val = _val[top];
        return true;
    }

    bool empty() const {
        return top == -1;
    }
};

int P(int n, int x) {
    PStack S;
    int fv0 = 1, fv1 = 2 * x;
    while (n > 1) {
        S.push(--n, x);
        S.push(--n, x);
    }
    for (int i = n; i > 1; i--) {

    }
    while (!S.empty()) {

    }
    return n ? fv1 : fv0;
}

TEST(StackApp, 3) {
    printf("%d %d %d %d %d\n", P(0, 1), P(1, 1), P(2, 1), P(3, 1), P(4, 1), P(5, 1));
}