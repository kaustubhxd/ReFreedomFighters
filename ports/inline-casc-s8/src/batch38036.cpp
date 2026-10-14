// batch38036.cpp - cascade s8 batch 38036: 0x5d73b0 (event handler of the two-list control).
#include "ff.h"

extern "C" void THISCALL ext_5d7bc0(u8 *self);
extern "C" void THISCALL ext_5d7e00(u8 *self);
extern "C" void THISCALL ext_5d7ef0(u8 *base, u32 k, u32 p);   // ret 8
typedef u32(THISCALL *v0_t)(void *);
typedef u32(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v3_t)(void *, u32, u32, u32);
typedef u32(THISCALL *v4_t)(void *, u32, u32, u32, u32);
#define SLOT(o, off, T) ((T)(*(u8 **)(*(u8 **)(o) + (off))))
#define ENG G(u8 *, 0x70039c)
#define TABLE (*(u8 **)(ENG + 0x9b))
#define U32F(off) (*(u32 *)(self + (off)))
#define U16F(off) (*(u16 *)(self + (off)))

// clears the screen / flushes the table's pending items: eng slot 0xc(0,0,0,0), then table slot 0xa4 for each pending item (slot 0xac count) and slot 0xa0(arg).
static void flush_table(u32 arg) {
  u8 *e = ENG;
  SLOT(e, 0xc, v4_t)(e, 0, 0, 0, 0);
  u8 *t = TABLE;
  s32 n = (s32)SLOT(t, 0xac, v0_t)(t);
  while (n > 0) {
    t = TABLE;
    SLOT(t, 0xa4, v0_t)(t);
    n--;
  }
  t = TABLE;
  SLOT(t, 0xa0, v1_t)(t, arg);
}

// 0x5d73b0, thiscall(id, extra) ret 8, returns 0. Dispatches on the u16 `id` against four ids stored at this+0x142 / +0x148 / +0x146 / +0x14c: the first counts one more step (+0x156) and either
// flushes the table with the string 0x6b5e18 (flag +0x1d5), re-runs 0x5d7bc0 while the step is below the list count (+0x14e slot 0x14), or resets the engine and flushes with this+0x15e;
// the second finds the first 12-byte record at this+0x4c (n at +0x48) whose first dword is not below *extra and passes its index to 0x5d7ef0; the third finishes a pending 0x5d7bc0 (+0x1c3 / +0x1e6)
// and runs 0x5d7e00 unless +0x1cc is set; the fourth sets the step to the list count and tells this[0x44] (slot 0x128) about the first id.
static u32 THISCALL fn5d73b0(u8 *self, u32 idarg, u8 *extra) {
  u16 id = (u16)idarg;
  if (id == U16F(0x142)) {
    U32F(0x156) = U32F(0x156) + 1;
    if (self[0x1d5] != 0) {
      flush_table(0x6b5e18);
      return 0;
    }
    u8 *l = *(u8 **)(self + 0x14e);
    s32 c = (s32)SLOT(l, 0x14, v0_t)(l);
    if ((s32)U32F(0x156) < c) {
      ext_5d7bc0(self);
      return 0;
    }
    u8 *e = ENG;
    SLOT(e, 0x1cc, v1_t)(e, 0);
    e = ENG;
    u8 *o = *(u8 **)(e + 0x190f);
    SLOT(o, 0xbc, v0_t)(o);
    e = ENG;
    *(u32 *)(e + 0x1b40) = 0x3f800000;
    flush_table((u32)(self + 0x15e));
    return 0;
  }
  if (id == U16F(0x148)) {
    u8 *base = self + 0x48;
    u8 *edx = self + 0x4c;
    u8 *end = base + (U32F(0x48) * 3 + 1) * 4;
    if (edx != end) {
      u32 v = *(u32 *)extra;
      end = base + (*(u32 *)base * 3 + 1) * 4;
      while (*(s32 *)edx < (s32)v) {
        edx += 0xc;
        if (edx == end) break;
      }
    }
    s32 k = ((s32)(edx - base) - 4) / 12;
    ext_5d7ef0(base, (u32)k, (u32)extra);
    return 0;
  }
  if (id == U16F(0x146)) {
    if (self[0x1c3] != 0 && self[0x1e6] != 0) {
      ext_5d7bc0(self);
      self[0x1e6] = 0;
    }
    if (self[0x1cc] == 0) ext_5d7e00(self);
    return 0;
  }
  if (id == U16F(0x14c)) {
    u8 *l = *(u8 **)(self + 0x14e);
    U32F(0x156) = SLOT(l, 0x14, v0_t)(l);
    u8 *o = *(u8 **)(self + 0x44);
    SLOT(o, 0x128, v3_t)(o, U16F(0x142), 0, 0);
  }
  return 0;
}
PCREG(5d73b0, fn5d73b0);
