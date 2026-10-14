#include "ff.h"

// 0x521780: thiscall(this, arg0, arg1) ret 8 - conditional flag setter
// Tests [this+0x260b], stores args at [this+0x2610] and [this+0x2609]
// If [this+0x260b]==0 and arg0!=0, sets [this+0x260b]=1
void __thiscall sub_521780(int* ecx, int arg0, unsigned char arg1) {
    int* this_obj = ecx;
    unsigned char* flag_ptr = (unsigned char*)((char*)this_obj + 0x260b);
    int* store_ptr = (int*)((char*)this_obj + 0x2610);
    unsigned char* byte_ptr = (unsigned char*)((char*)this_obj + 0x2609);

    *store_ptr = arg0;
    *byte_ptr = arg1;

    if (*flag_ptr == 0 && arg0 != 0) {
        *flag_ptr = 1;
    }
}
PCREG(521780, sub_521780);
