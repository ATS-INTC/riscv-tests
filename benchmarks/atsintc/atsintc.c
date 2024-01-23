#include<stdint.h>
#include<stdio.h>

int main( int argc, char* argv[] ) {
    printf("test begin\n");
    uint64_t *read_reg = 0x10000000;
    uint64_t *write_reg = 0x10000008;
    int i = 0;
    for (i = 0; i < 8; i ++) {
        *write_reg = 0x19990100 + i;
		printf("read res 0x%lx\n", *read_reg);
    }
    for (i = 0; i < 8; i ++) {
        printf("a read res 0x%lx\n", *read_reg);
    }

    return 0; 
}

