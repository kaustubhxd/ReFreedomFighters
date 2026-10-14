#include "ff.h"

// 0x62c9d0: cdecl(arg0, arg1) - multi-branch conditional dispatcher
int __cdecl sub_62c9d0(int arg0, int arg1) {
    if (arg1 == 0xf) {
        return 0;
    } else if (arg1 == 0x12 || arg1 == 0x29) {
        *(int*)arg0 = 0x62ca20;
        return 0x1e;
    } else {
        if (*(int*)((char*)arg0 + 0xc) == 0 && arg1 == 0x1c) {
            return 0x34;
        }
        *(int*)arg0 = 0x51f230;
        return -1;
    }
}
PCREG(62c9d0, sub_62c9d0);
