#include "ff.h"

// 0x4e5080: stdcall(this, arg) ret 4 - nested dereference with byte offset indexing
// Reads [arg+0x80] as table, [ecx+0xc] as byte offset, dereferences [table + byte_offset]
int __stdcall sub_4e5080(int* ecx, int* arg) {
    int* table = (int*)arg[0x20];  // [arg + 0x80]
    int byte_offset = ecx[3];      // [ecx + 0xc] - used as byte offset
    return *(int*)((char*)table + byte_offset);
}
PCREG(4e5080, sub_4e5080);
