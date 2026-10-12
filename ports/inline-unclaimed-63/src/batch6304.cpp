// batch6304.cpp - unclaimed-63 batch 4 (docs/20-unclaimed-63.md, from core-todo/residue-02.txt): two functions.
//   0x5dc3e0, CImpactResponse::End() (GC name, vtable; high): calls the cdecl function pointer at 0x6762ec with the dword
//     [this+0x4c] pushed (caller cleans); then returns (ret, no arguments).
//   0x647320 (GUESS FUN_647320): arg x (a pointer): y = [x+8]; w = word [y+0x5a]; if w: v = [[0x70039c]+0x190f]->vtbl[+0x20](w);
//     e = 0x63eab0(ECX = v); if e: base = 0x658d00(ECX = e); for k in 0..[this+0x11]-1: dword at base+0x1c+0x24*k = 0.
//     Callee pops 4 (ret 4). 0x63eab0 and 0x658d00 are original code, stubbed by the spec.
#include "ff.h"

extern "C" u32 THISCALL ext_63eab0(void *self);   // original code, stubbed by the spec
extern "C" u32 THISCALL ext_658d00(void *self);   // original code, stubbed by the spec

typedef u32(THISCALL * call1_fn)(void *, u32);
typedef void (*cdecl1_fn)(u32);

// 0x5dc3e0 (CImpactResponse::End, high).
static void THISCALL impactResponseEnd(u8 *self) {
  ((cdecl1_fn)G(u32, 0x6762ec))(*(u32 *)(self + 0x4c));
}
PCREG(5dc3e0, impactResponseEnd);

// 0x647320 (GUESS FUN_647320). The count is read as a dword at this+0x11 (unaligned).
static void THISCALL unnamed647320(u8 *self, u8 *x) {
  u32 y = *(u32 *)(x + 8);
  u16 w = *(u16 *)(y + 0x5a);
  if (w != 0) {
    u32 rm = G(u32, 0x70039c);
    u32 mgr = *(u32 *)(rm + 0x190f);
    u32 v = ((call1_fn)(*(u32 *)(*(u32 *)mgr + 0x20)))((void *)mgr, (u32)w);
    u32 e = ext_63eab0((void *)v);
    if (e != 0) {
      u32 base = ext_658d00((void *)e);
      for (u32 k = 0; k < *(u32 *)(self + 0x11); k++)
        *(u32 *)(base + 0x1c + 0x24 * k) = 0;
    }
  }
}
PCREG(647320, unnamed647320);
