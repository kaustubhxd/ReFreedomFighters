// batch1024.cpp - unclaimed-10, batch 20 (docs/20-unclaimed-10.md): 0x437050, no GC name (GUESS: class and name unknown),
// thiscall, one argument, ret 4. r = this->vt[+0x58](arg). If r is non-null: r+0xc = 1 (byte); and if the dword at r was 0
// when read (before the store), the bit 0x40 of the byte at r+0x2e is cleared. The vtable slot is an unverified callee (stubbed).
#include "ff.h"

#define VT(o) (*(void ***)(o))

typedef u32(THISCALL *Slot58x)(u8 *self, u32 a);  // this->vt[+0x58](arg) -> object pointer

// 0x437050 (GUESS: unnamed, no GC name; high-level role unknown)
static void THISCALL unnamed437050(u8 *self, u32 arg) {
  u8 *r = (u8 *)(unsigned long)((Slot58x)VT(self)[0x58 / 4])(self, arg);
  if (r) {
    u32 first = *(u32 *)r;
    r[0xc] = 1;
    if (first == 0) r[0x2e] &= 0xbf;
  }
}
PCREG(437050, unnamed437050);
