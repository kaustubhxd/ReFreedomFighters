// batch3014.cpp - unclaimed-30: batch 14 (docs/20-unclaimed-30.md, claim 1). Unnamed in the name map: 0x519950 [thiscall, ret 4;
// the name is not in gc_pc_namemap.tsv]. It reads a float from this+0x14's slot 0x2d4 and discards it, then takes the element 0 of
// the array held by the object at [arg+8] (0x5003d0, exe code). If that element's byte +4 is 0 or 2, the element takes the float
// (dword) and the type 2; otherwise it reports line 0xd5 (message 0x69c938 with format 0x69c6b0) and calls the assert hook
// (int3 when none is set).
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(u8 *arr, u32 index);   // exe code: element pointer of an array object (ret 4)

typedef void (*reportStrFn)(void *, const char *, const char *);

static u8 *rdp(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return (u8 *)v; }

static void THISCALL unnamed519950(u8 *self, u8 *x) {
  u8 *lo = rdp(self + 0x14);
  float f = vcall<float>(lo, 0x2d4);
  u8 *elem = ext_5003d0(rdp(x + 8), 0);
  u8 t = elem[4];
  if (t != 0 && t != 2) {
    void *r = vcall<void *>(G(u8 *, 0x700390), 0x20, (const char *)0x69c8e0, 0xd5);
    (*(reportStrFn *)(*(u8 **)r + 0x2c))(r, (const char *)0x69c6b0, (const char *)0x69c938);
    typedef void (*hookfn)();
    hookfn h = G(hookfn, 0x7003b0);
    if (h) h();
    else __builtin_debugtrap();   // the exe's int3 when no assert hook is set
    return;
  }
  *(float *)elem = f;           // the element takes the value and the type 2
  elem[4] = 2;
}
PCREG(519950, unnamed519950);
