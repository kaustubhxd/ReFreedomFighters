// batch210087.cpp - Sonnet-w3a: 0x5bda50 (forward a command to this[0x44] with a manager id, then to the object named by this[0x7d])
#include "ff.h"

static inline u32 ld32(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }

static u8 *mgr() { return (u8 *)ld32(G(u8 *, 0x70039c) + 0x9b); }

static void THISCALL fn5bda50(u8 *self, u32 a, u32 b) {
  u8 *t = *(u8 **)(self + 0x44);
  u8 *vt = *(u8 **)t;
  if (self[0x74]) {  // @5bda50_a
    u32 id = vcall<u32, u8 *>(mgr(), 0x4c, t);  // @5bda50_b
    typedef u32 (THISCALL *F3)(u8 *, u32, u32, u32);
    (*(F3 *)(vt + 0x130))(*(u8 **)(self + 0x44), b, a, id);  // @5bda50_c
  } else {
    u32 id = vcall<u32, u32, u32>(mgr(), 0x4c, b, 0);  // @5bda50_d
    typedef u32 (THISCALL *F2)(u8 *, u32, u32);
    (*(F2 *)(vt + 0x128))(*(u8 **)(self + 0x44), a, id);  // @5bda50_e
  }
  u8 *o = (u8 *)vcall<u32, u32>(mgr(), 0x58, ld32(self + 0x7d));  // @5bda50_f
  if (o) {  // @5bda50_g
    u8 *ovt = *(u8 **)o;
    u32 id2 = vcall<u32, u32, u32>(mgr(), 0x4c, b, 0);  // @5bda50_h
    typedef u32 (THISCALL *F2)(u8 *, u32, u32);
    (*(F2 *)(ovt + 0x128))(o, a, id2);  // @5bda50_i
  }
}
PCREG(5bda50, fn5bda50);
