// batch37110.cpp - cascade s6 batch 37110: 0x58c150.
#include "ff.h"

extern "C" void THISCALL ext_4de7a0(u8 *m);   // resets a matrix-like block (plain ret)
typedef u32(THISCALL *v2_t)(void *, u32, u32);
typedef void (*cd2_t)(void *, u32);

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x58c150, stdcall(a, p1, p2) ret 0xc, returns bool: applies the pair (p1, p2) to the object at a+0x44 (O). When O answers slot 0x1e0 (0x1007d1) it takes slots 0x2e0 / 0x98
// itself; otherwise its slot-0x20 delegate takes them when that one answers 0x1007d1. Else the object registered for a+0x106 in the global at 0x70038c (slot 0xcc) must exist
// (error 0x377 when not): p2 is cleared, p1 reset (0x4de7a0), O (if it answers 0x200074) is positioned through slots 0x3a8 / 0x390, receives slot 0x98 and the object is looked up
// again; the result is whether the final object is non-null.
static u8 STDCALL fn58c150(u8 *a, u8 *p1, u32 *p2) {
  u8 *O = *(u8 **)(a + 0x44);
  u8 *ebx = O;
  if ((u8)vcall<u32>(O, 0x1e0, 0x1007d1u)) {
    vcall<void>(O, 0x2e0, (u32)p1, (u32)p2);
    vcall<void>(O, 0x98, (u32)p1, (u32)p2);
  } else {
    u8 *P = (u8 *)vcall<u32>(O, 0x20);
    bool done = false;
    if (P) {
      u8 *P2 = (u8 *)vcall<u32>(O, 0x20);
      if ((u8)vcall<u32>(P2, 0x1e0, 0x1007d1u)) {
        ebx = (u8 *)vcall<u32>(O, 0x20);
        vcall<void>(ebx, 0x2e0, (u32)p1, (u32)p2);
        vcall<void>(ebx, 0x98, (u32)p1, (u32)p2);
        done = true;
      }
    }
    if (!done) {
      void *g = *(void **)0x70038c;
      u32 R = vcall<u32>(g, 0xcc, D32(a, 0x106));
      if (!R) {
        u8 *lg = *(u8 **)0x700390;
        void *L = (void *)(*(v2_t **)lg)[0x20 / 4](lg, 0x6ac6d0, 0x377);
        (*(cd2_t **)L)[0x2c / 4](L, 0x6ac9a8);
        return 0;
      }
      p2[0] = 0;
      p2[1] = 0;
      p2[2] = 0;
      ext_4de7a0(p1);
      if ((u8)vcall<u32>(O, 0x1e0, 0x200074u)) {
        u32 t = vcall<u32>(O, 0x3a8, (u32)p1, (u32)p2);
        vcall<void>(O, 0x390, t);
      }
      vcall<void>(O, 0x98, (u32)p1, (u32)p2);
      ebx = (u8 *)vcall<u32>(g, 0xcc, D32(a, 0x106));
    }
  }
  return ebx ? 1 : 0;
}
PCREG(58c150, fn58c150);
