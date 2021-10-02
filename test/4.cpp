//
// Created by hasee on 2021/9/25.
//

#include <iostream>

#include <gtest/gtest.h>

using namespace std;

int Index(string s, string t) {
    int i = 0, j = 0;
    while (i < s.length() && j < t.length()) {
        if (s[i] == t[j]) {
            i++, j++;
        } else {
            i += 1 - j;
            j = 0;
        }
    }
    if (j == t.length())
        return i - j;
    return -1;
}

TEST(String, testIndex) {
    string s = "test a unbelievable laaff word", t = "aff";
    int i = Index(s, t);
    if (i > -1)
        cout << s.substr(i, t.length());
    else
        cout << "no sub found";
    cout << endl;
}

void get_next(string &T, int next[]) {
    int i = 1, j = 0;
    next[1] = 0;

    string s, t;

    while (i < T.length()) {

        s = T.substr(0, i + 1), t = T.substr(0, j + 1);
        cout << s << " - " << t << endl;

        if (!j || T[i] == T[j]) {
            next[++i] = ++j;
        } else
            j = next[j];
    }
}

void get_nextval(string &T, int next[]) {
    get_next(T, next);

    int i = 1, j = 0;

    while (i <= T.length()) {
        if (j == 0 || T[i] == T[j]) {
            ++i, ++j;
            if (T[i - 1] != T[j - 1])
                next[i] = j;
            else
                next[i] = next[j];
        } else
            j = next[j];
    }
}

int Index_KMP(string &S, string &T) {
    int i = 0, j = 0;
    int next[T.length() + 1];
//    int next[] = {-1, 0, 1, 1, 2, 3};

    get_next(T, next);
    string s, t;

    while (i < S.length() && j < T.length()) {
        s = S.substr(0, i + 1), t = T.substr(0, j + 1);
        cout << s << " - " << t << endl;
        if (S[i] == T[j]) {
            i++, j++;
        }
        else
            j ? j = next[j] : i++;
    }
    if (j == T.length())
        return i - T.length();
    return -1;
}

TEST(String, nextval) {
    string t = "ababa";
    int next[t.length()];
    get_nextval(t, next);
    for (int i = 1; i <= t.length(); ++i) {
        cout << next[i] << " ";
    }
    cout << endl;
}

TEST(String, KMP) {
    string s = "bbabaabababaab";
    string t = "ababa";
    int i = Index_KMP(s, t);
    cout << s.substr(i, t.length()) << endl;
}