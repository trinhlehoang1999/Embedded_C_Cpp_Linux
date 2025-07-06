#include "stdio.h"

int a_linker; // .bss --> RAM
int b_linker = 10; //.data --> RAM

static int c_linker; // .bss --> RAM
static int d_linker = 5; //.data --> RAM

int main() {

    int e_linker; // stack
    int f_linker = 2;

    static int g_linker;
    static int z_linker = 1;

    printf("Hello, World12345!\n");


    return 0;
}