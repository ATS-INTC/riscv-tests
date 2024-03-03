#include<stdint.h>
#include<stdio.h>

int main( int argc, char* argv[] ) {
    printf("test begin\n");
    uint64_t *read_reg = 0x10000000;
    uint64_t *write_reg0 = 0x10000008;
    uint64_t *write_reg1 = 0x10000010;
    uint64_t *write_reg2 = 0x10000018;
    uint64_t *write_reg3 = 0x10000020;
    uint64_t *write_reg4 = 0x10000028;
    uint64_t *write_reg5 = 0x10000030;
    uint64_t *write_reg6 = 0x10000038;
    uint64_t *write_reg7 = 0x10000040;

    int i = 0;
    for (i = 0; i < 1; i ++) {
        *write_reg0 = 0x01 + i;
		    printf("wait a moment\n");
    }
    for (i = 0; i < 2; i ++) {
        *write_reg1 = 0x11 + i;
		    printf("wait a moment\n");
    }
    for (i = 0; i < 3; i ++) {
        *write_reg2 = 0x21 + i;
		    printf("wait a moment\n");
    }
    for (i = 0; i < 4; i ++) {
        *write_reg3 = 0x31 + i;
		    printf("wait a moment\n");
    }
    for (i = 0; i < 5; i ++) {
        *write_reg4 = 0x41 + i;
		    printf("wait a moment\n");
    }
    for (i = 0; i < 6; i ++) {
        *write_reg5 = 0x51 + i;
		    printf("wait a moment\n");
    }
    for (i = 0; i < 7; i ++) {
        *write_reg6 = 0x61 + i;
		    printf("wait a moment\n");
    }
    for (i = 0; i < 8; i ++) {
        *write_reg7 = 0x71 + i;
		    printf("wait a moment\n");
    }
    uint64_t res = 0;
    for (i = 0; i < 36; i ++) {
      res = *read_reg;
      printf("a read res 0x%lx\n", res);
    }

    return 0; 
}

