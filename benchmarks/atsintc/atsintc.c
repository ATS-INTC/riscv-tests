#include<stdint.h>
#include<stdio.h>

void test_priority_queue();
void test_extintr_handler();

int main( int argc, char* argv[] ) {
    printf("test begin\n");
    // test_priority_queue();
    test_extintr_handler();
    return 0; 
}

void test_priority_queue() {
    int i = 0, j = 0, prio = 8;
    for (i = prio - 1; i >= 0; i --) {
        uint64_t *write_regi = 0x10000008 + 8 * i;
        for(j = 0; j < i + 1; j ++) {
            *write_regi = i * 16 + j;
            printf("enqueue 0x%lx\n", i * 16 + j);
        }
    }
    uint64_t *read_reg = 0x10000000;
    uint64_t res = 0;
    for (i = 0; i < 36; i ++) {
      res = *read_reg;
      printf("read res 0x%lx\n", res);
    }
}

void test_extintr_handler() {
    int i = 0;
    int count = 4;

    
    
    uint64_t *ext0 = 0x10000900;
    uint64_t *ext1 = 0x10000908;
    uint64_t *ext2 = 0x10000910;
    uint64_t *ext3 = 0x10000918;
    uint64_t *ext4 = 0x10000920;
    uint64_t *ext5 = 0x10000928;

    for (i = 0; i < count; i ++) {
        *ext0 = 0x0106 + i;
        printf("ext0 registe handler\n");
    }
    for (i = 0; i < count; i ++) {
        *ext1 = 0x0116 + i;
        printf("ext1 registe handler\n");
    }
    for (i = 0; i < count; i ++) {
        *ext2 = 0x0126 + i;
        printf("ext2 registe handler\n");
    }
    for (i = 0; i < count; i ++) {
        *ext3 = 0x0136 + i;
        printf("ext3 registe handler\n");
    }
    for (i = 0; i < count; i ++) {
        *ext4 = 0x0146 + i;
        printf("ext4 registe handler\n");
    }
    for (i = 0; i < count; i ++) {
        *ext5 = 0x0156 + i;
        printf("ext5 registe handler\n");
    }

    uint64_t *extintr0 = 0x10200000;
    uint64_t *extintr1 = 0x10200008;
    uint64_t *extintr2 = 0x10200010;
    uint64_t *extintr3 = 0x10200018;
    uint64_t *extintr4 = 0x10200020;
    uint64_t *extintr5 = 0x10200028;

    
    for (i = 0; i < count; i ++) {
        *extintr2 = 0x01 + i;
        printf("extintr2 interrupt occurred\n");
    }
    for (i = 0; i < count; i ++) {
        *extintr3 = 0x01 + i;
        printf("extintr3 interrupt occurred\n");
    }
    
    for (i = 0; i < count; i ++) {
        *extintr4 = 0x01 + i;
        printf("extintr4 interrupt occurred\n");
    }
    for (i = 0; i < count; i ++) {
        *extintr5 = 0x01 + i;
        printf("extintr5 interrupt occurred\n");
    }
    uint64_t *write_reg0 = 0x10000008;
    for (i = 0; i < count; i ++) {
        *write_reg0 = 0x019990109 + i;
        printf("wait a moment\n");
    }
    for (i = 0; i < count; i ++) {
        *extintr1 = 0x01 + i;
        printf("extintr1 interrupt occurred\n");
    }
    for (i = 0; i < count; i ++) {
        *extintr0 = 0x01 + i;
        printf("extintr0 interrupt occurred\n");
    }
    
    uint64_t *read_reg = 0x10000000;
    uint64_t res = 0;
    for (i = 0; i < 1; i ++) {
        *ext4 = 0x0146 + i;
        printf("ext4 registe handler\n");
    }
    for (i = 0; i < 1; i ++) {
        *extintr4 = 0x01 + i;
        printf("extintr4 interrupt occurred\n");
    }
    for (i = 0; i < count * 8; i ++) {
        res = *read_reg;
        printf("read extintr handler 0x%lx\n", res);
    }

}

