#include "ff.h"

// 0x646040: thiscall, checks if [ecx+0x291] == 0 && [ecx+0x295] == 0, returns 1 or 0
int __thiscall sub_646040(int* ecx) {
    int val1 = *(int*)((char*)ecx + 0x291);
    int val2 = *(int*)((char*)ecx + 0x295);
    return (val1 == 0 && val2 == 0) ? 1 : 0;
}
PCREG(646040, sub_646040);
