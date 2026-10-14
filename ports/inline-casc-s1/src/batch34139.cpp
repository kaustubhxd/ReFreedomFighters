// batch34139.cpp - cascade tier E, batch 34139: 0x589980 (add to a 16-slot set), 0x5af3a0 (resolve a name to an object).
#include "ff.h"

extern "C" void THISCALL ext_58a320(void *self);               // plain ret
extern "C" u32 *THISCALL ext_5af130(void *self, u32 a);        // ret 4
extern "C" u32 THISCALL ext_5af300(void *self, u32 o);         // ret 4

// 0x589980, thiscall(v) ret 4: set of up to 16 dwords at this+0x3c, count at +0x38. When v is not present: when the count is 0x10 ext_58a320(this) runs (compacts the set) and when it is still 0x10
// the logger [0x700390]->slot0x20(0x6abf90, 0x14d) q, q->slot0x2c(q, 0x6abfec) (cdecl, ecx = vtable) prints an error and nothing is added; otherwise v is appended and the count incremented.
static void THISCALL fn589980(u8 *self, u32 v) {
  u32 *a = (u32 *)(self + 0x3c);
  u32 n = *(u32 *)(self + 0x38);
  u32 i = 0;
  while (i != n && a[i] != v) i++;
  if (i != *(u32 *)(self + 0x38)) return;
  if (*(u32 *)(self + 0x38) == 0x10) {
    ext_58a320(self);
    if (*(u32 *)(self + 0x38) == 0x10) {
      u8 *q = vcall<u8 *>(G(u8 *, 0x700390), 0x20, 0x6abf90u, 0x14du);
      typedef void (*pf)(u8 *, u32);
      (*(pf *)(*(u8 **)q + 0x2c))(q, 0x6abfec);
      return;
    }
  }
  u32 c = *(u32 *)(self + 0x38);
  a[c] = v;
  *(u32 *)(self + 0x38) = *(u32 *)(self + 0x38) + 1;
}
PCREG(589980, fn589980);

// 0x5af3a0, thiscall(a) ret 4: when any of [this], [this+4], [this+8] is zero the logger prints an error (slot 0x20(0x6b0f44, 0x20) then q->slot0x2c(q, 0x6b0fd0), cdecl) and 0 is returned.
// Otherwise r = ext_5af130([this+4], a); null r or null [r] gives 0; w = [this+8]->slot0x98([r], 0); o = [[0x70039c]+0x9b]->slot0x58(w); null o gives 0; else returns ext_5af300(this, o).
static u32 THISCALL fn5af3a0(u8 *self, u32 a) {
  if (*(u32 *)self == 0 || *(u32 *)(self + 4) == 0 || *(u32 *)(self + 8) == 0) {
    u8 *q = vcall<u8 *>(G(u8 *, 0x700390), 0x20, 0x6b0f44u, 0x20u);
    typedef void (*pf)(u8 *, u32);
    (*(pf *)(*(u8 **)q + 0x2c))(q, 0x6b0fd0);
    return 0;
  }
  u32 *r = ext_5af130(*(u8 **)(self + 4), a);
  if (!r) return 0;
  u32 e = *r;
  if (!e) return 0;
  u32 w = vcall<u32>(*(u8 **)(self + 8), 0x98, e, 0u);
  u32 o = vcall<u32>(*(u8 **)(G(u8 *, 0x70039c) + 0x9b), 0x58, w);
  if (!o) return 0;
  return ext_5af300(self, o);
}
PCREG(5af3a0, fn5af3a0);
