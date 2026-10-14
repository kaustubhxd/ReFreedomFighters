#include "ff.h"

extern "C" int __cdecl ext_5390b0(void);

// 0x533ba0: cdecl() - calls verified function, returns 1
unsigned char __cdecl sub_533ba0(void) {
    ext_5390b0();
    return 1;
}
PCREG(533ba0, sub_533ba0);
