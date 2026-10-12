// batch1016.cpp - unclaimed-04 batch 17 (docs/20-unclaimed-04.md): CEntityTracker builder 0x5c0500 (thiscall, no args).
// The exe's /GS cookie check (0x633654) at the end has no effect when the cookie is valid, so it is not called here.
#include "ff.h"

typedef u32(THISCALL *vf0_t)(void *self);
typedef u32(THISCALL *vf1_t)(void *self, u32 a);
typedef u32(THISCALL *vf2_t)(void *self, u32 a, u32 b);

static inline u32 vslot(void *o, u32 off) {
  return *(u32 *)(*(u32 *)o + off);
}
static inline u32 call0(void *o, u32 off) {
  return ((vf0_t)vslot(o, off))(o);
}
static inline u32 call1(void *o, u32 off, u32 a) {
  return ((vf1_t)vslot(o, off))(o, a);
}
static inline u32 call2(void *o, u32 off, u32 a, u32 b) {
  return ((vf2_t)vslot(o, off))(o, a, b);
}

extern "C" void *ext_41e290(u32 size);  // cdecl allocator, original code (hooked by the spec)
typedef void(__attribute__((cdecl)) *qsort_t)(void *base, u32 n, u32 size, void *cmp);
#define CRT_QSORT (*(qsort_t *)0x676450)

// count * size, or 0xffffffff when the product does not fit in 32 bits (the exe's seto/neg/or sequence)
static inline u32 scaledSize(u32 count, u32 size) {
  u64 p = (u64)count * size;
  return (p >> 32) ? 0xffffffffu : (u32)p;
}

// 0x5c0500
static void THISCALL entityTrackerBuild(u8 *self) {
  u8 *g = *(u8 **)0x70039c;
  u8 *mgr = *(u8 **)(g + 0x9b);
  u8 *x1 = (u8 *)call2(*(u8 **)(mgr + 0xadc), 0x25c, 0x685f44, 0);
  u8 *s = *(u8 **)(x1 + 0x18);
  u32 n = call0(s, 0x14);
  *(u32 *)(self + 0x54) = n;
  *(u8 **)(self + 0x50) = (u8 *)ext_41e290(scaledSize(n, 0x17));

  u32 index = 0;
  u32 off = 0;
  if (s) {
    u32 out40 = 0;
    call1(s, 0x4c, (u32)&out40);
    u32 y = call1(s, 0x5c, (u32)&out40);
    if (out40 != 0) {
      do {
        u8 *m = *(u8 **)(*(u8 **)0x70039c + 0x9b);
        u32 e = call1(m, 0x58, y);
        if (e && (u8)call1((void *)e, 0x1e0, 0x200006) && *(u32 *)(e + 0x54) != 0) {
          u8 *r = *(u8 **)(self + 0x50) + off;
          *(u32 *)r = e;
          u32 out28 = 0;
          call2((void *)e, 0x80, (u32)&out28, (u32)(r + 4));
          r[0x10] = 1;
          s32 gv = (s32)(*(u32 *)(*(u8 **)0x70039c + 0x40) - 0x1400u);
          *(float *)(r + 0x11) = (float)gv * *(float *)0x6785e4;
          index++;
          off += 0x17;
        }
        y = call1(s, 0x5c, (u32)&out40);
      } while (out40 != 0);
    }
  }

  *(u32 *)(self + 0x54) = index;
  CRT_QSORT(*(void **)(self + 0x50), index, 0x17, (void *)0x5bfdd0);

  u32 cnt = *(u32 *)(self + 0x54);
  *(u32 *)(self + 0x4c) = (u32)ext_41e290(scaledSize(cnt, 4));
  for (u32 k = 0; k < cnt; k++) {
    ((u32 *)*(u32 *)(self + 0x4c))[k] = k;
    *(u16 *)(*(u8 **)(self + 0x50) + 0x17 * (k + 1) - 2) = (u16)k;
  }

  *(float *)(self + 0x60) = 500.0f;
  u64 prod = (u64)0x51eb851fu * cnt;
  *(u32 *)(self + 0x5c) = (u32)((prod >> 32) >> 3) + 1;
}
PCREG(5c0500, entityTrackerBuild);
