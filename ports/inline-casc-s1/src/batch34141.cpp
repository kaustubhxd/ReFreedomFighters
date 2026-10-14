// batch34141.cpp - cascade tier E, batch 34141: 0x5f29e0 (trim a history list), 0x5f48c0 (append records to a vector).
#include "ff.h"

extern "C" void THISCALL ext_5fd6f0(void *self);              // plain ret
extern "C" u32 THISCALL ext_4cc5f0(void *self);               // plain ret, string length through a pointer
extern "C" void THISCALL ext_5f55e0(void *self);              // plain ret
extern "C" void ext_42ab62(u32 a);                            // cdecl
extern "C" void THISCALL ext_605940(void *self, u32 a, u32 b, u32 c);   // ret 0xc
typedef void (*hook_t)();

// 0x5f29e0, thiscall plain: m = [this+0xc]; ext_5fd6f0([m+4]); keep = 0; when ext_4cc5f0(m+0x14) is non-zero keep = this->slot0x8c(m+0x14). While [m+0x98] > keep (unsigned): o = [0x70039c]->slot0x190();
// o->slot0x184(o, 0xa, [m+0x98] + 3, 0x679e6c) (cdecl, ecx = the count + 3) and [m+0x98]--; finally [m+0x98] = keep.
static void THISCALL fn5f29e0(u8 *self) {
  u8 *m = *(u8 **)(self + 0xc);
  ext_5fd6f0(*(u8 **)(m + 4));
  u32 keep = 0;
  m = *(u8 **)(self + 0xc);
  if (ext_4cc5f0(m + 0x14)) keep = vcall<u32>(self, 0x8c, (u32)(*(u8 **)(self + 0xc) + 0x14));
  m = *(u8 **)(self + 0xc);
  if (*(u32 *)(m + 0x98) <= keep) {
    *(u32 *)(m + 0x98) = keep;
    return;
  }
  do {
    u8 *o = vcall<u8 *>(G(u8 *, 0x70039c), 0x190);
    u8 *vt = *(u8 **)o;
    m = *(u8 **)(self + 0xc);
    typedef void (*pf)(u8 *, u32, u32, u32);
    (*(pf *)(vt + 0x184))(o, 0xa, *(u32 *)(m + 0x98) + 3, 0x679e6c);
    m = *(u8 **)(self + 0xc);
    (*(u32 *)(m + 0x98))--;
    m = *(u8 **)(self + 0xc);
  } while (*(u32 *)(m + 0x98) > keep);
  *(u32 *)(m + 0x98) = keep;
}
PCREG(5f29e0, fn5f29e0);

// 0x5f48c0, thiscall(a, b, c) ret 0xc: ext_5f55e0(c); n = c (the argument slot itself) overwritten by a->slot0x5c(&n); for each of n: when [c+8] >= [c+4] ext_42ab62(0x6b89b4) and the assert hook [0x7003b0] (int3 when null) run and carry on;
// slot = [c] + 8 * [c+8]; [c+8]++; ext_605940(slot, a, b, this).
static void THISCALL fn5f48c0(u8 *self, u8 *a, u32 b, u8 *c) {
  u32 n = (u32)c;
  ext_5f55e0(c);
  vcall<void>(a, 0x5c, (u32)&n);
  for (u32 i = 0; i < n; i++) {
    if (*(u32 *)(c + 8) >= *(u32 *)(c + 4)) {
      ext_42ab62(0x6b89b4);
      hook_t h = G(hook_t, 0x7003b0);
      if (!h) __asm__ volatile("int3");
      h();
    }
    u32 size = *(u32 *)(c + 8);
    u8 *slot = *(u8 **)c + size * 8;
    *(u32 *)(c + 8) = size + 1;
    ext_605940(slot, (u32)a, b, (u32)self);
  }
}
PCREG(5f48c0, fn5f48c0);
