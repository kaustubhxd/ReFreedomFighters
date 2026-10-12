// batch6353.cpp - unclaimed-63 gap-band batch 53: 0x4dcbb0 (C-set; no GC name), thiscall, one stack argument b (a flag), ret 4.
//   Recursive over the child list (the children are walked through the original code: the port calls 0x4dcbb0 itself through ext_).
//   If b != 0: if this[+0x3c] & 0x200000: return. 0x4da770(this, 0) (thiscall, ret 4).
//     If this[+0x3c] & 0x40000: if this[+0x64] != 0 and (this[+0x3c] & 0xff) != 0: c = this[+0x50] ? [..+0x54] : 0;
//       r = 0x4daff0([c + 8]) (thiscall, no arguments); if r != 0: r->vtbl[+0x320](this), this[+0x64] = 0.
//       Then 0x4dae60(this) (thiscall, no arguments).
//     0x4dc630(0x200000, 0) (thiscall, two arguments, ret 8). Go to the list part.
//   If b == 0: if !(this[+0x3c] & 0x200000): return. 0x4dc630(0, 0x200000). If this[+0x3c] & 0x200c00: return.
//     If this[+0x3c] & 0x40000: if this[+0x64] == 0: 0x4d9ce0(this); 0x4d9bf0(this). Then 0x4d9d20(this, 0) (thiscall, ret 4).
//   List part: L = this[+0x54]; f = L ? [[L+0xc]+0x23] : 0x200002. If f & 0x100000: for node = L[+0x50]; node; node = node[+0x60]:
//     0x4dcbb0(node, b) (recursive).
//   Tail: m = this[+0x6c]; if m != 0 and this[+0x5a] != 0 and not (f & 0x800000): eng = [0x70039c]; eng[+0x190f]->vtbl[+0x190](this, m).
//     If this[+0x6c] == m: return; else this[+0x3c] |= 0x100000.
//   Helpers: 0x4da770 (ret 4), 0x4dc630 (ret 8), 0x4d9d20 (ret 4), 0x4dae60/0x4d9ce0/0x4d9bf0/0x4daff0 (plain). Hooks in the spec
//   except the recursion (the original's own code).
#include "ff.h"

extern "C" void THISCALL ext_4da770(void *self, u32 a);          // thiscall, one argument, ret 4, other area's code (stubbed)
extern "C" void THISCALL ext_4dc630(void *self, u32 a, u32 b);  // thiscall, two arguments, ret 8, other area's code (stubbed)
extern "C" void THISCALL ext_4d9d20(void *self, u32 a);         // thiscall, one argument, ret 4, other area's code (stubbed)
extern "C" void THISCALL ext_4dae60(void *self);                 // thiscall, no arguments, stubbed
extern "C" void THISCALL ext_4d9ce0(void *self);                 // thiscall, no arguments, stubbed
extern "C" void THISCALL ext_4d9bf0(void *self);                 // thiscall, no arguments, parked SEH routine (stubbed here)
extern "C" u32 THISCALL ext_4daff0(void *self);                  // thiscall, no arguments, returns an object, stubbed
extern "C" void THISCALL ext_4dcbb0(void *self, u32 b);          // this function (the recursion runs the original)

typedef void(THISCALL * a1_fn)(void *, u32);
typedef void(THISCALL * a2_fn)(void *, u32, u32);

// 0x4dcbb0 (C-set).
static void THISCALL unnamed4dcbb0(u8 *self, u32 b) {
  u32 f;
  if ((u8)b != 0) {   // the original tests bl only
    if (*(u32 *)(self + 0x3c) & 0x200000u)
      return;
    ext_4da770((void *)self, 0u);
    if (*(u32 *)(self + 0x3c) & 0x40000u) {
      if (*(u32 *)(self + 0x64) != 0 && (*(u32 *)(self + 0x3c) & 0xffu) != 0) {
        u32 p = *(u32 *)(self + 0x50);
        u32 c = p != 0 ? *(u32 *)(p + 0x54) : 0;
        u32 r = ext_4daff0((void *)*(u32 *)(c + 8));
        if (r != 0) {
          ((a1_fn)(*(u32 *)(*(u32 *)r + 0x320)))((void *)r, (u32)self);
          *(u32 *)(self + 0x64) = 0;
        }
      }
      ext_4dae60((void *)self);
    }
    ext_4dc630((void *)self, 0x200000u, 0u);
  } else {
    if ((*(u32 *)(self + 0x3c) & 0x200000u) == 0)
      return;
    ext_4dc630((void *)self, 0u, 0x200000u);
    if (*(u32 *)(self + 0x3c) & 0x200c00u)
      return;
    if (*(u32 *)(self + 0x3c) & 0x40000u) {
      if (*(u32 *)(self + 0x64) == 0)
        ext_4d9ce0((void *)self);
      ext_4d9bf0((void *)self);
    }
    ext_4d9d20((void *)self, 0u);
  }
  u32 L = *(u32 *)(self + 0x54);
  f = (L != 0) ? *(u32 *)(*(u32 *)(L + 0xc) + 0x23) : 0x200002u;
  if (f & 0x100000u) {
    for (u32 node = *(u32 *)(L + 0x50); node != 0; node = *(u32 *)(node + 0x60))
      ext_4dcbb0((void *)node, b);
  }
  u32 m = *(u32 *)(self + 0x6c);
  L = *(u32 *)(self + 0x54);
  f = (L != 0) ? *(u32 *)(*(u32 *)(L + 0xc) + 0x23) : 0x200002u;
  if (m != 0 && *(u16 *)(self + 0x5a) != 0 && (f & 0x800000u) == 0) {
    u32 eng = G(u32, 0x70039c);
    u32 obj = *(u32 *)(eng + 0x190f);
    ((a2_fn)(*(u32 *)(*(u32 *)obj + 0x190)))((void *)obj, (u32)self, m);
  }
  if (*(u32 *)(self + 0x6c) != m)
    *(u32 *)(self + 0x3c) |= 0x100000u;
}
PCREG(4dcbb0, unnamed4dcbb0);
