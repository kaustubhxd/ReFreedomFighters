// batch867.cpp - area 50 (residue-9 candidate): 0x4d2910 [68 instr, thiscall, one stack arg, ret 4; no name in the map (GUESS
// "copy the records of a source iterator into this's buffer")]. The source's iterator is at arg+0x4008. Each record r (from
// its vt +0x5c, with a flag) has a size (+0 + +8 + 0xc, rounded up to 4): the size is stored at this's buffer (base +0x4004) at
// the offset from the allocator 0x4cd9b0 (stood in), and the record's bytes are copied after it (memcpy). Then this+0x4008's vt
// +0x4 gets the copy's data pointer. The source's vt +0x4c starts the walk.
#include "ff.h"

#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

extern "C" u32 THISCALL ext_4cd9b0(void *buf, u32 size, u32 flag);   // allocator: an offset into the base (stood in)

// 0x4d2910 (name GUESS).
static void THISCALL Fn4d2910(u8 *self, u8 *arg) {
  u8 *it = arg + 0x4008;
  if (it == 0) return;
  u32 f = 0;
  vcall<void>(it, 0x4c, &f);
  u32 r = vcall<u32>(it, 0x5c, &f);
  if (f == 0) return;
  u8 *dstobj = self + 0x4008;
  do {
    u8 *buf = self + 0x40b4;
    u32 sz = U32((u8 *)r, 0) + U32((u8 *)r, 8) + 0xc;
    u32 al = (sz + 7) & 0xfffffffcu;
    u32 off = ext_4cd9b0(buf, al, 1);
    u8 *P = (u8 *)FP(self, 0x4004);
    U32(P, off) = al;
    u8 *dst = P + 4 + off;
    typedef void *(*memcpy_t)(void *, const void *, u32);
    (*(memcpy_t *)0x67626c)(dst, (const void *)r, sz);
    vcall<void>(dstobj, 0x4, dst);
    r = vcall<u32>(it, 0x5c, &f);
  } while (f != 0);
}
PCREG(4d2910, Fn4d2910);
