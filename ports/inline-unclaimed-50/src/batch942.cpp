// batch942.cpp - 0x5eeab0 (no name in the map), read in full (2026-10-12). Thiscall (ECX = this), one float arg v (ebp+8), ret 4, void.
// For each element E in the list [this+5, this+9): the object is *(*E) (the element points to a cell whose first dword is the object).
// Call 0x5ac5b0 on that object (thiscall, one float v; stood in). Then call 0x5ec2b0 with ECX = this+0x15, args (v, -1) (stood in).
#include "ff.h"

#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))

extern "C" void THISCALL ext_5ac5b0(void *self, float v);          // stood in (one float arg, callee pops 4)
extern "C" void THISCALL ext_5ec2b0(void *self, float v, s32 n);   // stood in (two args, -1 second)

// 0x5eeab0 (no name in the map).
static void THISCALL Apply5eeab0(u8 *self, float v) {
  u32 *it = (u32 *)U32(self, 5);
  u32 *end = (u32 *)U32(self, 9);
  for (; it != end; it++) {
    u8 *cell = (u8 *)*it;
    void *obj = *(void **)cell;
    ext_5ac5b0(obj, v);
  }
  ext_5ec2b0((void *)U32(self, 0x15), v, -1);
}
PCREG(5eeab0, Apply5eeab0);
