// u69_55.cpp - area 69, group 55 (slice 8). A UTF-8 style decoder over a char* held in the object (self points at the char*). No callees.
#include "ff.h"

// 0x4cc500, GetNextUTC4Char(char**) (GC map medium). thiscall no args (ret), returns the decoded value in eax.
// *self is the read position. A zero byte returns 0 and does not advance. A byte with bit 7 set counts its leading one bits (n, the count is n+1 in the original's counter);
// the consumed length is 1 for ASCII and n for a lead byte; the payload is the lead byte's low bits, then 6 bits per continuation byte. *self advances by the consumed length.
static u32 THISCALL nextUtf4cc500(char **self) {
  u8 *p = (u8 *)*self;
  s8 bl = (s8)*p;
  if (bl == 0)
    return 0;
  s32 edx = bl;
  u32 eax = 0x80;
  s32 ecx = (s32)(eax - 0x7f);
  if (bl < 0) {
    do {
      eax = (u32)((s32)eax >> 1);
      ecx += 1;
    } while ((eax & (u32)edx) != 0);
  }
  s32 esi = (ecx <= 1) ? ecx : ecx - 1;
  u32 val = 0xfe;
  if (ecx < 7) {
    for (s32 k = 7 - ecx; k > 0; --k)
      val += val;
  }
  val = (~val) & (u32)(u8)bl;
  if (esi > 1) {
    for (s32 i = 1; i < esi; ++i) {
      s32 c = (s8)p[i];
      c &= 0x3f;
      val = (val << 6) | (u32)c;
    }
  }
  *self = (char *)(p + esi);
  return val;
}
PCREG(4cc500, nextUtf4cc500);
