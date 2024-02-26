#include<stdint.h>
#include<stdio.h>

int main( int argc, char* argv[] ) {
    printf("test begin\n");
    uint64_t *read_reg = 0x10000000;
    uint64_t *write_reg = 0x10000008;
    int i = 0;
    for (i = 0; i < 3; i ++) {
        *write_reg = 0x19990100 + i;
		    printf("wait a moment\n");
    }
    uint64_t res = 0;
    for (i = 0; i < 3; i ++) {
      res = *read_reg;
      printf("a read res 0x%lx\n", res);
    }

    return 0; 
}

