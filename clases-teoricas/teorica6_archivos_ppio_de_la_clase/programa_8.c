#include <stdio.h>

void f() {
    int x = 1;
    printf("En f, x = %d\n", x);
}

void g() {
    f();
}

int main() {
    g();
    return 0;
}
