#include <stdio.h>

typedef struct { int toto; long tata; } Foo;
typedef struct { long tutu; int titi; } Bar;

int main() {
    Foo foo = { 42,666 };
    Bar bar = *((Bar*)&foo);

    printf("%ld - %d", bar.tutu, bar.titi);; //140728898420778-666
    return 0;
}