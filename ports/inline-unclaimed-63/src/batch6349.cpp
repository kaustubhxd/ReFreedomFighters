// batch6349.cpp - unclaimed-63 gap-band batch 49: 0x4cd470 (C-set; no GC name), thiscall, one stack argument A, ret 4, returns a pointer.
//   O = this[+0x24]. If O != 0: O->vtbl[+0x4c](&L); n = O->vtbl[+0x5c](&L); if L != 0: e = n + (2 - this[+0x18]) * 4;
//     O->vtbl[+0x44](&L) (the callee writes L's out value); then the store below uses e. If L == 0: e = A.
//     Store: [e] = A. If O->vtbl[+0x14]() == 0: if this[+0x24] != 0: vtbl[0](this[+0x24], 1) (deleting destructor); this[+0x24] = 0.
//   If O == 0 at entry: e = 0x4cd540(this, A) - 4 (original code, another area's claim; stubbed by the spec).
//   Tail: f = e + (this[+0x18] - 2) * 4; f[0] = this[+0x20]; f[1] = 0; if this[+0x20] != 0: old[+4] = f, else this[+0x1c] = f;
//   this[+0x20] = f; return e + 4.
#include "ff.h"

extern "C" u32 THISCALL ext_4cd540(void *self, u32 a);   // thiscall, one stack argument, original code, stubbed by the spec

typedef void(THISCALL * p1_fn)(void *, u32 *);
typedef u32(THISCALL * q1_fn)(void *, u32 *);
typedef void(THISCALL * a1_fn)(void *, u32);
typedef u32(THISCALL * q0_fn)(void *);
typedef void(THISCALL * dtor_fn)(void *, u32);

// 0x4cd470 (C-set).
static u32 THISCALL unnamed4cd470(u8 *self, u32 a) {
  u32 e;
  u32 o = *(u32 *)(self + 0x24);
  if (o != 0) {
    u32 L;
    ((p1_fn)(*(u32 *)(*(u32 *)o + 0x4c)))((void *)o, &L);
    u32 n = ((q1_fn)(*(u32 *)(*(u32 *)o + 0x5c)))((void *)o, &L);
    if (L != 0) {
      e = n + (2u - *(u32 *)(self + 0x18)) * 4u;
      ((p1_fn)(*(u32 *)(*(u32 *)o + 0x44)))((void *)o, &L);
    } else {
      e = a;
    }
    *(u32 *)e = a;
    u32 o2 = *(u32 *)(self + 0x24);
    if (((q0_fn)(*(u32 *)(*(u32 *)o2 + 0x14)))((void *)o2) == 0) {
      u32 d = *(u32 *)(self + 0x24);
      if (d != 0)
        ((dtor_fn)(*(u32 *)(*(u32 *)d)))((void *)d, 1u);
      *(u32 *)(self + 0x24) = 0;
    }
  } else {
    e = ext_4cd540((void *)self, a) - 4u;
  }
  u32 f = e + (*(u32 *)(self + 0x18) - 2u) * 4u;
  *(u32 *)f = *(u32 *)(self + 0x20);
  *(u32 *)(f + 4) = 0;
  u32 old = *(u32 *)(self + 0x20);
  if (old != 0)
    *(u32 *)(old + 4) = f;
  else
    *(u32 *)(self + 0x1c) = f;
  *(u32 *)(self + 0x20) = f;
  return e + 4;
}
PCREG(4cd470, unnamed4cd470);
