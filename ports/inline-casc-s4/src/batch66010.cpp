// batch66010.cpp - cascade s4 batch 66010: 0x427150 (tier F row; Sonnet 5.5 took over idx 2318).
#include "ff.h"

typedef s32(*fseek_t)(u32, u32, u32);
typedef u32(*fread_t)(void *, u32, u32, u32);

// 0x427150, stdcall(f, off, addr) ret 0xc: fseek(f, off, 0); fread(&x, 1, 4, f); x == 0 -> 0.
// Loop: fseek(f, off + 0xc, 0); fread a, b, c (three dwords, 1 x 4 bytes each); a <= addr < a + b (unsigned) -> return c - a + addr.
// Otherwise off += 0x28; fseek(f, off, 0); fread(&x, 1, 4, f); x == 0 -> return 0.
static u32 STDCALL fn427150(u32 f, u32 off, u32 addr) {
  u32 x, a, b, c;
  G(fseek_t, 0x6763e8)(f, off, 0);
  G(fread_t, 0x6763f8)(&x, 1, 4, f);
  if (!x) return 0;
  for (;;) {
    G(fseek_t, 0x6763e8)(f, off + 0xc, 0);
    G(fread_t, 0x6763f8)(&a, 1, 4, f);
    G(fread_t, 0x6763f8)(&b, 1, 4, f);
    G(fread_t, 0x6763f8)(&c, 1, 4, f);
    if (addr >= a && addr < a + b) return c - a + addr;
    off += 0x28;
    G(fseek_t, 0x6763e8)(f, off, 0);
    G(fread_t, 0x6763f8)(&x, 1, 4, f);
    if (!x) return 0;
  }
}
PCREG(427150, fn427150);
