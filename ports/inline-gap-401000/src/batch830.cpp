// batch830.cpp - unported-PC batch 830 (residue-01, docs/20-unclaimed-65.md): 0x5bd750 (CCheckInsideByType::CopyEventDataBlock), a thiscall
// with one stack argument (the source, ret 4). It reads the source through 0x4e5e60 (no arguments, ecx = source) and 0x4e5e40 (same), stores
// the low words at this+0x75 and +0x77, sets this+0x74 = (third 0x4e5e60 result != 0), clears the dword at +0x79, sets bit (first result mod 32)
// in it, and stores 0x4e5e60's result (ecx = source) at +0x7d. The helpers are other claims, hooked by address in the spec (GUESS).
#include "ff.h"

extern "C" u32 THISCALL ext_4e5e60(u8 *self);   // thiscall, no arguments (hooked in the spec)
extern "C" u32 THISCALL ext_4e5e40(u8 *self);   // thiscall, no arguments (hooked in the spec)

static void THISCALL fn5bd750(u8 *self, u8 *src) {
  const u32 bit = ext_4e5e60(src);
  *(u16 *)(self + 0x75) = (u16)ext_4e5e40(src);
  *(u16 *)(self + 0x77) = (u16)ext_4e5e40(src);
  const u32 t = ext_4e5e60(src);
  *(u8 *)(self + 0x74) = (u8)(t != 0);
  u32 bits = 0;
  bits |= 1u << (bit & 31);
  *(u32 *)(self + 0x79) = bits;
  *(u32 *)(self + 0x7d) = ext_4e5e60(src);
}

PCREG(5bd750, fn5bd750);
