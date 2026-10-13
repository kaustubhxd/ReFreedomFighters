// batch4129.cpp - unclaimed-41 batch 29 (slice 13): 0x5c1910 FUN_5c1910 (GUESS name; thiscall, no arguments, ret 0, void).
// The helper 0x5c1aa0 (called once, with ecx = this) is in this file too. The /GS cookie check is not reproduced.
#include "ff.h"

typedef u32(THISCALL * f0_t)(u8 *);
typedef u32(THISCALL * f1_t)(u8 *, u32);
typedef u32(THISCALL * f2_t)(u8 *, u32, u32);
typedef u32(THISCALL * f4_t)(u8 *, u32, u32, u32, u32);

static u32 vslot(u8 *o, u32 off) {
  return *(u32 *)(*(u8 **)o + off);
}

// 0x5c1aa0: this+0x111 (a dword) skips the list walk. Otherwise the list at this+0xe4 (zero-terminated dwords) is walked with
// the index in edi (starting at this+0xe8): each element is passed to (this+0x10d).vt[0x25c](element, 0), and the result object r
// gets vt[0xbc](0) when edi == this+0x48, else vt[0xbc](1). Then, if the render-manager flag at 0x1b5d is zero, this.vt[0x68](0x10, 0).
static void helper5c1aa0(u8 *self) {
  if (*(u32 *)(self + 0x111) == 0) {
    u32 *esi = *(u32 **)(self + 0xe4);
    u32 edi = *(u32 *)(self + 0xe8);
    u32 cur = *esi;
    if (cur != 0) {
      do {
        u8 *obj = *(u8 **)(self + 0x10d);
        u8 *r = (u8 *)((f2_t)vslot(obj, 0x25c))(obj, cur, 0u);
        if (r != 0) {
          if (edi == *(u32 *)(self + 0x48))
            ((f1_t)vslot(r, 0xbc))(r, 0u);
          else
            ((f1_t)vslot(r, 0xbc))(r, 1u);
        }
        esi++;
        cur = *esi;
        edi++;
      } while (cur != 0);
    }
  }
  if (*(u32 *)(G(u8 *, 0x70039c) + 0x1b5d) == 0)
    ((f2_t)vslot(self, 0x68))(self, 0x10u, 0u);
}

static void THISCALL fn5c1910(u8 *self) {
  u8 *rm = G(u8 *, 0x70039c);
  u8 *o = *(u8 **)(rm + 0x9b);
  u8 *X1 = *(u8 **)(o + 0xadc);
  u32 e0 = ((f2_t)vslot(X1, 0x25c))(X1, 0x6b3bc0u, 0u);
  *(u32 *)(self + 0xe0) = e0;
  if (e0 == 0) {
    u32 e1 = ((f4_t)vslot(X1, 0x294))(X1, 0x6b3bc0u, 0x67f610u, 0u, 1u);
    *(u32 *)(self + 0xe0) = e1;
    u8 *o3 = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    u8 *r = (u8 *)((f0_t)vslot(o3, 0x138))(o3);
    u32 e0v = *(u32 *)(self + 0xe0);
    u8 *o4 = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    u32 V = ((f2_t)vslot(o4, 0x4c))(o4, e0v, 2u);
    ((f2_t)vslot(r, 0x60))(r, 0x6b3bc0u, V);
  }

  if (*(u8 *)(self + 0x10c) == 0) {
    u8 *Y = G(u8 *, 0x70038c);
    u32 e = ((f1_t)vslot(Y, 0x20))(Y, (u32)self);
    u32 edx;
    if (e == 0) {
      u32 fnp = *(u32 *)(Y + 8);
      bool calls = (fnp != 0) && !(*(u32 *)(Y + 0xc) > (u32)self) && !((u32)self >= *(u32 *)(Y + 0x10));
      if (calls) {
        edx = ((f0_t)fnp)(self);
      } else {
        if (*(u32 *)(self - 4) == 0)
          ((f1_t)vslot(Y, 0xac))(Y, (u32)self);
        edx = *(u32 *)(self - 4);
      }
    } else {
      edx = 0;
    }
    u8 *Z = *(u8 **)(self + 0xe0);
    ((f1_t)vslot(Z, 0x21c))(Z, edx);
  }

  // flags section
  u8 *W = G(u8 *, 0x7003b8);
  u8 *V2 = *(u8 **)(W + 0x2c15);
  if (*(u8 *)(V2 + 0x103f) != 0) {
    *(u32 *)(self + 0x88) = 0xau;
    *(u32 *)(self + 0xe4) = 0x6eef78u;
    *(u32 *)(self + 0xe8) = 3u;
    *(u32 *)(self + 0x48) = 7u;
    *(u32 *)(self + 0x4c) = 7u;
  } else {
    *(u32 *)(self + 0xe4) = 0x6eef68u;
    *(u32 *)(self + 0xe8) = 0u;
  }

  u8 *A = *(u8 **)(self + 0x44);
  u32 al = ((f1_t)vslot(A, 0x1e0))(A, 0x100001u) & 0xff;
  u32 pv;
  if (al != 0)
    pv = *(u32 *)(self + 0x44);
  else
    pv = ((f0_t)vslot(A, 0x20))(A);
  *(u32 *)(self + 0x10d) = pv;
  helper5c1aa0(self);

  A = *(u8 **)(self + 0x44);
  ((f1_t)vslot(A, 0x3c))(A, 1u);
}
PCREG(5c1910, fn5c1910);
