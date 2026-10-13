// batch407.cpp - 0x4cfce0 (gap band parked row, 170 bytes; thiscall, three stack arguments a1, a2, a3, ret 0xc) and its
// forwarder 0x41ef30 (thiscall with the same three arguments; ecx = dword [this+0x31]; tail-jumps to 0x4cfce0).
// Body: old = dword [this+0x20f]; if old == -1: return. S = dword [this+0x8217]. ebx = a1 - old. edx = a2 + ebx.
// If ebx >= (S << 13): return. edx = min(edx, S * 0x1fff) (unsigned). Q = edx / S.
// edi = (((a3 & 0xf8) << 3 | (a3 & 0xf800)) << 3 | (a3 & 0xf80000)) << 7. Q2 = ebx / S.
// If (int)Q2 > (int)Q: return. Else for k = 0 .. Q - Q2 (count Q - Q2 + 1): word at base + 4k + 2 = 0, dword at base + 4k |= edi,
// with base = this + 0x217 + 4 * Q2.
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

static void THISCALL allocRangeBits(u8 *self, u32 a1, u32 a2, u32 a3) {
  u32 old = U32(self, 0x20f);
  if (old == 0xffffffffu)
    return;
  u32 S = U32(self, 0x8217);
  u32 ebx = a1 - old;
  u32 edx = a2 + ebx;
  if (ebx >= (S << 13))
    return;
  u32 eax = S * 0x1fffu;
  if (eax < edx)
    edx = eax;
  u32 Q = edx / S;
  u32 edi = ((((a3 & 0xf8u) << 3) | (a3 & 0xf800u)) << 3) | (a3 & 0xf80000u);
  edi <<= 7;
  u32 Q2 = ebx / S;
  if ((s32)Q2 > (s32)Q)
    return;
  u8 *base = self + 0x217 + 4 * Q2;
  u32 count = Q - Q2 + 1;
  for (u32 k = 0; k < count; k++) {
    u8 *addr = base + 4 * k;
    *(u16 *)(addr + 2) = 0;
    *(u32 *)addr |= edi;
  }
}

extern "C" void THISCALL ext_4cfce0(void *self, u32 a1, u32 a2, u32 a3);   // target by address (exe code)

static void THISCALL forwardTo4cfce0(u8 *self, u32 a1, u32 a2, u32 a3) {
  ext_4cfce0((void *)(unsigned long)U32(self, 0x31), a1, a2, a3);
}

PCREG(4cfce0, allocRangeBits);
PCREG(41ef30, forwardTo4cfce0);
