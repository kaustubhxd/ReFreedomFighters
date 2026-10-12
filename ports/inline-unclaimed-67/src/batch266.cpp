// batch266.cpp - unclaimed area 67, slice floor(addr/16) mod 20 == 6 (FUN_ names; bodies from the PC bytes).
#include "ff.h"

static inline u32 rdw(u32 p, u32 off) { return *(u32 *)(unsigned long)(p + off); }
static inline float rdf(u32 p, u32 off) { return *(float *)(unsigned long)(p + off); }

// 0x4dffe0, fastcall (ECX = out, EDX = b), one stack argument a, ret 4: out = b - a, componentwise on two floats.
static void FASTCALL subVec2(u8 *out, u8 *b, u8 *a) {
  u32 bp = (u32)(unsigned long)b, ap = (u32)(unsigned long)a;
  *(float *)out = rdf(bp, 0) - rdf(ap, 0);
  *(float *)(out + 4) = rdf(bp, 4) - rdf(ap, 4);
}
PCREG(4dffe0, subVec2);

// 0x43e5a0, thiscall, ret 4 (argument a): when (this[0x18] & 0xa) is zero, sets bit 2 if a != 0 and clears it if a == 0.
static void THISCALL setFlagBit2(u8 *selfP, u32 a) {
  u32 self = (u32)(unsigned long)selfP;
  u32 f = rdw(self, 0x18);
  if (f & 0xa)
    return;
  f = a != 0 ? (f | 4u) : (f & 0xfffffffbu);
  *(u32 *)(selfP + 0x18) = f;
}
PCREG(43e5a0, setFlagBit2);

// 0x479060, stdcall (ret 4, argument a): returns 1 for a == 8, 6 or 7, else 0.
static u8 STDCALL isMoveKind(u32 a) { return (a == 8 || a == 6 || a == 7) ? 1 : 0; }
PCREG(479060, isMoveKind);
