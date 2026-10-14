// batch903.cpp - gap band slice: 0x41e8a0 ZSysMem::Delete(void*) [thiscall, one stack arg (p), ret 4, returns al].
// Whole body read (2026-10-12; the earlier partial port in batch902 was discarded). Flow:
//  - p == 0: return 0. idx = this's slot +0x20 (p). If idx != 0: 0x4d1140 on the entry at this+0x31+4*idx, return 0.
//  - if the global manager (g+0x9b) exists and 0x41e650(manager, p) is true: return 0.
//  - hdr = p-0x10. If the object at this+0x2c exists, its slot +4 gets the size hdr[2] & 0x1fffffff.
//  - if hdr[2] < 0: b = p-0x20; bl = slot +0x88(b) ? 1 : 0. If hdr[1] > 1: hdr[1]--, 0x41f190(p), return 0. Otherwise unlink b from
//    the list (through b[0], b[1]; this+0x18 / this+0x1c for the ends), 0x41f190 on the two neighbours (+0x20), and if b[7] (+0x1c) is
//    set: if 0x41e680(p) is false by slot +0xd4, call slot +0x7c(0x67731c, b). Then 0x634d10(p, 0xd5, size of b). Free b (or 0x4cfdb0
//    on this+0x31 when the 0x40000000 bit is set in b[6]).
//  - else: hdr[1]--; if hdr[1] > 0 return 0. If hdr[3] != 0 and slot +0xd4 of this (on 0x41e680(p)) is false, bl = 1.
//    Free hdr (or 0x4cfdb0 when the 0x40000000 bit is set in hdr[2]).
//  - if bl: slot +0x84 of this. Return 1.
// Stand-ins: 0x4d1140, 0x41e680, 0x4cfdb0, 0x634d10, the free import (0x6762ec); real code: 0x41e650, 0x41f190.
#include "ff.h"

#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

extern "C" void THISCALL ext_4d1140(void *obj, void *p);            // stood in; ret 4
extern "C" bool THISCALL ext_41e650(void *mgr, void *p);            // real exe code; ret 4 (InBlock41e650)
extern "C" void THISCALL ext_41f190(void *self, void *p);           // real exe code; ret 4 (Fix41f190)
extern "C" u32 THISCALL ext_41e680(void *p);                        // stood in; ECX = p, returns eax
extern "C" void THISCALL ext_4cfdb0(void *obj, void *blk);          // stood in; ret 4
extern "C" void ext_634d10(void *p, u32 tag, u32 size);             // stood in; cdecl, three words

// 0x41e8a0 (name map: ZSysMem::Delete(void*)).
static u8 THISCALL Delete41e8a0(u8 *self, u8 *p) {
  if (!p) return 0;
  u32 idx = vcall<u32>(self, 0x20, (void *)p);
  if (idx) {
    ext_4d1140(FP(self, 0x31 + 4 * idx), p);
    return 0;
  }
  u8 *mgr = G(u8 *, 0x70039c);
  if (mgr) {
    u8 *m2 = (u8 *)FP(mgr, 0x9b);
    if (m2 && ext_41e650(m2, p)) return 0;
  }
  u8 bl = 0;
  u8 *hdr = p - 0x10;
  u8 *X = (u8 *)FP(self, 0x2c);
  if (X) vcall<void>(X, 4, U32(hdr, 8) & 0x1fffffffu);
  if ((s32)U32(hdr, 8) < 0) {
    u8 *b = p - 0x20;
    if (vcall<bool>(self, 0x88, (void *)b)) bl = 1;
    if ((s32)U32(hdr, 4) > 1) {
      U32(hdr, 4) = U32(hdr, 4) - 1;
      ext_41f190(self, p);
      return 0;
    }
    u32 e0 = U32(b, 0);
    u8 *c4 = (u8 *)FP(b, 4);
    if (c4) U32(c4, 0) = e0;
    else U32(self, 0x18) = e0;
    u8 *d0 = (u8 *)FP(b, 0);
    u32 e4 = U32(b, 4);
    if (d0) U32(d0, 4) = e4;
    else U32(self, 0x1c) = e4;
    U32(b, 0) = 0;
    U32(b, 4) = 0;
    if (c4) ext_41f190(self, c4 + 0x20);
    if (e0) ext_41f190(self, (u8 *)e0 + 0x20);
    if (U32(b, 0x1c)) {
      u32 x = ext_41e680(p);
      if (!vcall<bool>(self, 0xd4, x)) vcall<void>(self, 0x7c, (void *)0x67731cu, (void *)b);
    }
    ext_634d10(p, 0xd5u, U32(b, 0x18) & 0x1fffffffu);
    if (U32(b, 0x18) & 0x40000000u) ext_4cfdb0(FP(self, 0x31), b);
    else ((void (*)(void *))G(u32, 0x6762ec))(b);
  } else {
    U32(hdr, 4) = U32(hdr, 4) - 1;
    if ((s32)U32(hdr, 4) > 0) return 0;
    if (U32(hdr, 0xc) != 0) {
      u32 x = ext_41e680(p);
      if (!vcall<bool>(self, 0xd4, x)) bl = 1;
    }
    if (U32(hdr, 8) & 0x40000000u) ext_4cfdb0(FP(self, 0x31), hdr);
    else ((void (*)(void *))G(u32, 0x6762ec))(hdr);
  }
  if (bl) vcall<void>(self, 0x84);
  return 1;
}
PCREG(41e8a0, Delete41e8a0);
