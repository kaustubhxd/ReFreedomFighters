// batch210062.cpp - Sonnet-w3a: 0x4831d0 (toggle a pending-lookup state around a target object and notify it)
#include "ff.h"

static inline void st32(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline u32 ld32(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }

static void THISCALL fn4831d0(u8 *self, u8 *p) {
  u32 fl = ld32(self + 0x417);
  if (!(fl & 0x1800)) {  // @4831d0_a
    st32(self + 0x413, 0);
    if (!p) return;  // @4831d0_b
    vcall<u32>(self, 0x514);  // @4831d0_c
    st32(self + 0x417, ld32(self + 0x417) | 0x800);  // @4831d0_d
    u8 *mgr = (u8 *)ld32(G(u8 *, 0x70039c) + 0x9b);
    u8 *vt = *(u8 **)p;
    u32 id = vcall<u32, u8 *, u32>(mgr, 0x4c, self, 0);  // @4831d0_e
    u32 r = vcall<u32, u32, u32, u32, u32, u32>(mgr, 0x114, 0x68becc, 0, 0x68bcbc, 0x277, id);  // @4831d0_f
    typedef u32 (THISCALL *F)(u8 *, u32);
    (*(F *)(vt + 0x128))(p, r & 0xffff);  // @4831d0_g
    mgr = (u8 *)ld32(G(u8 *, 0x70039c) + 0x9b);
    st32(self + 0x413, vcall<u32, u8 *>(mgr, 0x4c, p));  // @4831d0_h
    return;
  }
  st32(self + 0x417, fl & 0xffffe7ffu);  // @4831d0_i
  u8 *mgr = (u8 *)ld32(G(u8 *, 0x70039c) + 0x9b);
  u8 *o = (u8 *)vcall<u32, u32>(mgr, 0x58, ld32(self + 0x413));  // @4831d0_j
  if (o) {
    u8 *vt = *(u8 **)o;
    mgr = (u8 *)ld32(G(u8 *, 0x70039c) + 0x9b);
    u32 r = vcall<u32, u32, u32, u32, u32, u32, u32>(mgr, 0x114, 0x68bedc, 0, 0x68bcbc, 0x280, 0, 0);  // @4831d0_k
    typedef u32 (THISCALL *F)(u8 *, u32);
    (*(F *)(vt + 0x128))(o, r & 0xffff);  // @4831d0_l
  }
  st32(self + 0x413, 0);
  if (p) vcall<u32, u8 *>(self, 0x594, p);  // @4831d0_m
}
PCREG(4831d0, fn4831d0);
