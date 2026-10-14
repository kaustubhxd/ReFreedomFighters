#include "ff.h"

// 0x62cc90: cdecl(arg0, arg1) - similar multi-branch conditional dispatcher
int __cdecl sub_62cc90(int arg0, int arg1) {
    if (arg1 == 0xf) {
        return 0;
    } else if (arg1 == 0x12) {
        if (arg0 != 0) {
            (*(int*)((char*)arg0 + 8))++;
            *(int*)arg0 = 0x6cf2b0;
        }
        return 0;
    } else {
        if (*(int*)((char*)arg0 + 0xc) == 0 && arg1 == 0x1c) {
            return 0x34;
        }
        *(int*)arg0 = 0x51f230;
        return -1;
    }
}
PCREG(62cc90, sub_62cc90);
