#include <stdio.h>

int main() {

    int sum = 0;
    int a[30];
    for (int i = 0; i < 30; ++i) {
        scanf("%d", &a[i]);
        if (a[i] <= 20)
            continue;
        sum += a[i];
    }

    return 0;
}
