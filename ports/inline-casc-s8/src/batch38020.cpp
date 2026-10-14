// batch38020.cpp - cascade s8 batch 38020: 0x64c8d0 (flush the pending-object list into the object manager).
#include "ff.h"

extern "C" u8 *THISCALL ext_63eab0(u8 *mgr, u32 id);   // ret 4
extern "C" u32 THISCALL ext_63f090(u8 *mgr, u8 *p);    // ret 4 (id in AX)
extern "C" void THISCALL ext_63da80(u8 *mgr, u8 *p);   // ret 4
extern "C" void THISCALL ext_648810(u8 *self, u8 **out, s32 v);   // ret 8
extern "C" void ext_634d10(void *dst, u32 val, u32 n);   // memset thunk, cdecl
typedef u32(THISCALL *v0_t)(void *);
typedef u32(THISCALL *v1_t)(void *, u32);
typedef u32(*hook_t)();
#define SLOT(o, off, T) ((T)(*(u8 **)(*(u8 **)(o) + (off))))
#define F32(off) (*(u32 *)(self + (off)))
#define FP(off) (*(u8 **)(self + (off)))

// 0x64c8d0, thiscall, no args, plain ret. Clears a 0x4000-byte index buffer from the manager's slot 0x20, resets the counters, calls slot 0x1c and then drains the pending list
// (count at +0x1010d, items from +0x10111): with +0x10028 set (always, unless the virtual call clears it) every item's node (item+8) gets a manager object through slot 0x8 of +0x10151
// (existing id -> 0x63eab0, otherwise a fresh one from the +0x218 pool with 0x63f090), is entered into the index buffer and the manager's id table (+0x68), refreshed with 0x63da80, and
// passed to 0x648810 with the negated +0x4c of its owner; every object in the +0x10089 table then gets its running index in byte +0x70. With the flag clear the items are appended
// back to the list (assert hook above 0x10 entries).
static void THISCALL fn64c8d0(u8 *self) {
  u8 *mgr = FP(0x1005d);
  self[0x10028] = 1;
  u8 *buf = (u8 *)SLOT(mgr, 0x20, v1_t)(mgr, 0x4000);
  F32(0x10071) = (u32)buf;
  ext_634d10(buf, 0, 0x4000);
  F32(0x10165) = 0;
  F32(0x10151) = 0;
  F32(0x10155) = 0;
  F32(0x10159) = 0;
  F32(0x1015d) = 0;
  F32(0x10161) = 0;
  F32(0x10169) = 0;
  F32(0x1016d) = 0;
  SLOT(self, 0x1c, v0_t)(self);
  F32(0x10081) = (u32)self;
  u32 *cnt = (u32 *)(self + 0x1010d);
  u32 i = 0;
  if (*cnt == 0) {
    *cnt = 0;
    return;
  }
  u32 *p = (u32 *)(self + 0x10111);
  do {
    u32 item = *p;
    if (self[0x10028] == 0) {
      if (*cnt + 1 > 0x10) {
        hook_t h = G(hook_t, 0x7003b0);
        if (!h) __asm__ volatile("int3");
        h();
      }
      cnt[*cnt + 1] = item;
      (*cnt)++;
    } else {
      u8 *m = FP(0x1005d);
      SLOT(m, 0x60, v0_t)(m);
      u8 *node = *(u8 **)(item + 8);
      u8 *o = FP(0x10151);
      u8 *esi = (u8 *)SLOT(o, 8, v0_t)(o);
      u8 *esi0 = esi;
      u16 nid = *(u16 *)(node + 0x5a);
      if (nid != 0) {
        *(u8 **)(esi + 0xc) = ext_63eab0(FP(0x1005d), nid);
      } else {
        u8 *pool = *(u8 **)(FP(0x1005d) + 0x218);
        u8 *e1 = (u8 *)SLOT(pool, 8, v0_t)(pool);
        u32 r = ext_63f090(FP(0x1005d), e1);
        *(u16 *)(node + 0x5a) = (u16)r;
        (*(u8 ***)(FP(0x1005d) + 0x68))[r & 0xfff] = e1;
        *(u32 *)(e1 + 0xc) = item;
        *(u8 **)(esi0 + 0xc) = e1;
      }
      u8 *edx = esi + 4;
      u8 *node8 = esi;   // [ebp-8] (reassigned to the manager object)
      (*(u8 ***)(self + 0x10071))[*(u16 *)(node + 0x5a) & 0xfff] = edx;
      u8 *e = *(u8 **)(esi + 0xc);
      if (!(e[5] & 1)) ext_63da80(FP(0x1005d), e);
      ext_63da80(FP(0x1005d), edx);
      u8 *x = *(u8 **)(esi0 + 0xc);
      x = *(u8 **)(x + 0xc);
      s32 v = *(s32 *)(x + 0x4c);
      ext_648810(self + 0x10089, &node8, -v);
      (*(u8 **)(node8 + 0xc))[8]++;
      u32 cn = *(u32 *)(self + 0x10089);
      if (cn != 0) {
        u8 **q = (u8 **)(self + 0x1008d);
        u32 k = 0;
        do {
          u8 *ob = *q;
          q++;
          ob[0x70] = (u8)(k + 1);
          k++;
        } while (k != *(u32 *)(self + 0x10089));
      }
    }
    i++;
    p++;
  } while (i != *cnt);
  *cnt = 0;
}
PCREG(64c8d0, fn64c8d0);
