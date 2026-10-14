// batch897.cpp - gap band slice: 0x41ec30 ZSysMem::NewRef(void*) [thiscall, one stack arg, ret 4, returns bool]. With no object at
// this+4 the result is true. Otherwise the object's slot +0x10 must accept the pointer (else false). Then the table at this+0x28
// gets 0xffffffff at index (object mask & p), and if the logger at 0x70038c exists its slot +0x30 is called (thiscall, three words:
// format 0x677334, index*4, and 4; the callee pops them).
#include "ff.h"

#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

// 0x41ec30 (name map: ZSysMem::NewRef).
static bool THISCALL NewRef41ec30(u8 *self, u32 p) {
  if (FP(self, 4) == 0) return true;
  if (!vcall<bool>(FP(self, 4), 0x10, p)) return false;
  u8 *obj = (u8 *)FP(self, 4);
  u32 idx = U32(obj, 0x10) & p;
  U32(FP(self, 0x28), 4 * idx) = 0xffffffffu;
  u8 *logger = G(u8 *, 0x70038c);
  if (logger) vcall<void>(logger, 0x30, (void *)0x677334u, idx << 2, 4u);
  return true;
}
PCREG(41ec30, NewRef41ec30);
