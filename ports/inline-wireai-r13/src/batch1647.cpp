// batch1647.cpp - ZActor::SetActiveMoveSet(u32 idx, bool force) (0x47b8d0, residue 13, 2026-10-12). Name map: high
// (ZActor[359]). Returns bool. Frame: no SEH, `and esp,-8` only. Unchanged index and force == 0: returns 1 at once.
// A slot without a move set (table at +0x49a + 4*idx is zero) returns 0. Otherwise it stores idx at +0x4ae and
// measures the move records that vslot 0x5a8 names for classes 3, 4, 5, 8 and 0xc: a record is the vector at +0x70
// (length through the CRT sqrt 0x634d7c) of the table row at manager+0x44 + index. Results go to +0x712..+0x71e,
// +0x75d, +0x761, +0x765, and the base move (+0x650) is activated with arg 1 when it is set. GUESS: the names of the
// record fields (+0x60, +0x64, +0x6c) and the slot 0x5a8 are from the code only.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_477740[];                     // ZActor::ActivateBaseMove (thiscall, two args)
extern "C" double VECTORCALL ext_634d7c(double);  // CRT sqrt (precise)
typedef void(THISCALL *ActBaseFn)(void *self, u32 a, u32 b);

// Row base of a record index: 0 for index 0 (the exe then reads near address zero), else the table at manager+0x44.
static u32 RowBase(u32 ix) {
  if (!ix) return 0;
  u8 *mgr = AT(u8 *, AT(u8 *, 0x70039c, 0), 0x9b);
  return AT(u32, mgr, 0x44) + ix;
}

// Length of the record's vector (x at +0x70, y at +0x74, z at +0x78): sqrt((x*x + y*y) + z*z) in float.
static float RowLen(u32 ix) {
  u8 *b = (u8 *)RowBase(ix);
  float y = AT(float, b, 0x74);
  float x = AT(float, b, 0x70);
  float z = AT(float, b, 0x78);
  float s = x * x + y * y + z * z;
  return (float)ext_634d7c((double)s);
}

u8 THISCALL ZActor_SetActiveMoveSet(u8 *self, u32 idx, u32 force) {
  if (AT(u32, self, 0x4ae) == idx && !(u8)force) return 1;
  if (AT(u32, self, 0x49a + idx * 4) == 0) return 0;
  AT(u32, self, 0x4ae) = idx;

  AT(u32, self, 0x712) = 0;
  AT(u32, self, 0x716) = 0;
  AT(u32, self, 0x71a) = 0;
  AT(u32, self, 0x71e) = 0;
  u8 *p = vcall<u8 *>(self, 0x5a8, 3u);
  if (p) AT(float, self, 0x712) = RowLen(AT(u32, p, 0));
  p = vcall<u8 *>(self, 0x5a8, 4u);
  if (p) AT(float, self, 0x716) = RowLen(AT(u32, p, 0));
  p = vcall<u8 *>(self, 0x5a8, 5u);
  if (p) AT(float, self, 0x71a) = RowLen(AT(u32, p, 0));

  float m = AT(float, self, 0x71a) > AT(float, self, 0x716) ? AT(float, self, 0x71a) : AT(float, self, 0x716);
  float best = m > AT(float, self, 0x712) ? m : AT(float, self, 0x712);
  AT(float, self, 0x71e) = best;
  AT(u32, self, 0x75d) = 0x41200000u;  // 10.0f
  AT(u32, self, 0x761) = 0x42c80000u;  // 100.0f

  p = vcall<u8 *>(self, 0x5a8, 8u);
  if (p) {
    u32 ix = AT(u32, p, 0);
    float len = RowLen(ix);
    AT(float, self, 0x761) = len;
    u32 base = RowBase(ix);
    float t = (float)AT(s32, base, 0x6c) * len;
    s32 n = (s32)(AT(u32, base, 0x64) - AT(u32, base, 0x60) + 1);
    AT(float, self, 0x75d) = t / (float)n;
  }
  AT(u32, self, 0x765) = AT(u32, self, 0x75d);

  p = vcall<u8 *>(self, 0x5a8, 0xcu);
  if (p) {
    u32 ix = AT(u32, p, 0);
    float len = RowLen(ix);
    u32 base = RowBase(ix);
    float t = (float)AT(s32, base, 0x6c) * len;
    s32 n = (s32)(AT(u32, base, 0x64) - AT(u32, base, 0x60) + 1);
    AT(float, self, 0x765) = t / (float)n;
  }

  u32 move = AT(u32, self, 0x650);
  if (move) {
    float keep = AT(float, self, 0x755);
    ((ActBaseFn)(void *)ext_477740)(self, move, 1);
    AT(float, self, 0x755) = keep;
  }
  return 1;
}
PCREG(47b8d0, ZActor_SetActiveMoveSet);
