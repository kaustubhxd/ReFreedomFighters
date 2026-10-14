// batch5755.cpp - unclaimed-57, band batch 55 (name GUESS): 0x5c7c30, thiscall, two stack args (w, unused), returns 0. If (word)w equals the
// word this+0x4c: obj = dword (dword 0x70039c)+0x9b; c2 = dword obj+0xae4; r = c2->vt[0](dword this+0x48, 0x677b5a) (thiscall, two args; stubbed);
// res = 0x589c20(global 0x7003b8 as ECX; args 0, r, -1, 0) (thiscall, four args; unverified, hooked and logged); 0x59a580(res) (thiscall, no
// args; hooked and logged). Returns 0 in every case.
#include "ff.h"

#define VT(o) (*(void ***)(o))
#define G(T, addr) (*(T *)(addr))

typedef u32(THISCALL *SlotA)(u8 *self, u32 a, u32 b);

extern "C" u32 THISCALL ext_589c20(u8 *self, u32 a, u32 b, u32 c, u32 d);  // hooked and logged in the spec
extern "C" void THISCALL ext_59a580(u8 *self);                             // hooked and logged in the spec

static u32 THISCALL unnamed5c7c30(u8 *self, u32 w, u32 unused) {
  (void)unused;
  if ((u16)w != *(u16 *)(self + 0x4c)) return 0;
  u8 *engine = G(u8 *, 0x70039c);
  u8 *obj = *(u8 **)(engine + 0x9b);
  u8 *c2 = *(u8 **)(obj + 0xae4);
  u32 r = ((SlotA)VT(c2)[0])(c2, *(u32 *)(self + 0x48), 0x677b5a);
  u8 *g = G(u8 *, 0x7003b8);
  u32 res = ext_589c20(g, 0, r, 0xffffffff, 0);
  ext_59a580((u8 *)(unsigned long)res);
  return 0;
}
PCREG(5c7c30, unnamed5c7c30);
