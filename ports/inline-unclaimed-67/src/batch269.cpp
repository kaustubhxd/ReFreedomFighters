// batch269.cpp - unclaimed area 67, GUESS name for 0x439320 (body from the PC bytes). SEH frame not reproduced:
// the flag path calls 0x439380 (SEH frame, cookie) as original code through ext_439380.
#include "ff.h"

extern "C" u32 THISCALL ext_439380(u8 *self, u32 a);     // SEH-frame helper, original code (ret 4)
extern "C" u32 STDCALL ext_439570(u32 x);                // lookup table walk (batch 42 of inline-batch45), original code (ret 4)

typedef u32 (THISCALL *F0)(u8 *self);
typedef u32 (THISCALL *F1)(u8 *self, u32 a);
static inline u32 rdw(u32 p, u32 off) { return *(u32 *)(unsigned long)(p + off); }

// 0x439320, stdcall (ret 0xc: three stack arguments p, a2, flag; ECX is not used). See docs/20-unclaimed-67.md, batch 269.
static u32 STDCALL guessSlotPick(u8 *pP, u32 a2, u32 flag) {
  u32 p = (u32)(unsigned long)pP;
  if (p == 0)
    return 0;
  if (rdw(p, 0) != 0)
    return 0;
  if ((u8)flag != 0)
    return ext_439380((u8 *)(unsigned long)(p - 4), a2);
  u32 esi = p - 4;
  u32 m = rdw(esi, 0x15);
  if (m == 0)
    return 0;
  u32 r0 = ((F0)rdw(rdw(m, 0), 0x14))((u8 *)(unsigned long)m);
  if ((int)a2 >= (int)r0)
    return 0;
  u32 r1 = ((F1)rdw(rdw(m, 0), 0x30))((u8 *)(unsigned long)m, a2);
  return ext_439570(r1);
}
PCREG(439320, guessSlotPick);
