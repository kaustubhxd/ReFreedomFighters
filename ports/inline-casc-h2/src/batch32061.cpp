#include "ff.h"

// 0x623050: cdecl(arg0, arg1, arg2, arg3) - byte copy loop
void __cdecl sub_623050(int* arg0_ptr, int arg1_limit, int* counter_ptr, int counter_limit) {
    if (*arg0_ptr == arg1_limit) {
        return;
    }

    while (*arg0_ptr != arg1_limit) {
        int dest_val = *counter_ptr;
        if (dest_val == counter_limit) {
            break;
        }

        int src_addr = *arg0_ptr;
        unsigned char byte_val = *(unsigned char*)src_addr;
        *(unsigned char*)dest_val = byte_val;

        (*counter_ptr)++;
        (*arg0_ptr)++;
    }
}
PCREG(623050, sub_623050);
