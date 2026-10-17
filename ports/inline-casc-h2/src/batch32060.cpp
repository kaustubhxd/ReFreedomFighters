#include "ff.h"

// 0x62cf00: cdecl(arg0, arg1) - complex conditional dispatcher
int __cdecl sub_62cf00(int arg0, int arg1) {
    if (arg1 == 0xf) {
        return 0;
    } else if (arg1 == 0x19) {
        (*(int*)((char*)arg0 + 8))++;
        *(int*)arg0 = 0x62dbb0;
        return 0;
    } else {
        if (*(int*)((char*)arg0 + 0xc) == 0 && arg1 == 0x1c) {
            return 0x34;
        }
        *(int*)arg0 = 0x51f230;
        return -1;
    }
}
PCREG(62cf00, sub_62cf00);
