#include "ff.h"

// 0x475910: thiscall(this, arg_byte) ret 4, setne byte at [ecx+0x3bb], returns eax
int __thiscall sub_475910(int* ecx, int arg) {
    char* target = (char*)((char*)ecx + 0x3bb);
    *target = (arg != 0) ? 1 : 0;  // setne sets to 1 if not equal to 0, else 0
    return (unsigned char)*target;  // Return the value that was set
}
PCREG(475910, sub_475910);
