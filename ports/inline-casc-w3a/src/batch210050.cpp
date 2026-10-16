// batch210050.cpp - Sonnet-w3a: /GS-protected token classifier with a cursor callback
#include "ff.h"

extern "C" void FASTCALL ext_633654(u32 cookie);  // /GS check
extern "C" u32 ext_62c5b0(u8 *s, u32 key);
extern "C" int ext_628c10(u8 *s);

static u32 fn628a70(u8 *a, u32 b, u32 c) {
  u8 buf[0x84];
  u32 loc88 = b;
  u8 *loc8c = buf;
  u8 loc5;
  typedef u32 (*CB)(u8 *, u32 *, u32, u8 **, u8 *);
  (*(CB *)(a + 0x3c))(a, &loc88, c, &loc8c, &loc5);  // @628a70_a
  if (loc88 != c) {  // @628a70_b
    ext_633654(0);
    return 0;
  }
  *loc8c = 0;  // @628a70_c
  if (ext_62c5b0(buf, 0x6bfe40) && *(u32 *)(a + 0x44) == 2) {  // @628a70_d
    ext_633654(0);
    return (u32)a;
  }
  int idx = ext_628c10(buf);  // @628a70_e
  if (idx == -1) {
    ext_633654(0);
    return 0;
  }
  u32 v = ((u32 *)0x6f4408)[idx];  // @628a70_f
  ext_633654(0);
  return v;
}
PCREG(628a70, fn628a70);
