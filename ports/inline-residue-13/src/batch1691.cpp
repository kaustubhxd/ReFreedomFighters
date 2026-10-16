// batch1691.cpp - 0x461570 (GUESS, residue 13 gap band, 2026-10-12). Thiscall, three stack arguments (a float, b, c), ret 0xc.
// SEH frame not reproduced. When this+0x6c is zero: p = 0x41e290(0x2c) (cdecl, hooked); p non-null: LINKSORTREFTAB ctor
// (0x4ccad0, hooked; thiscall, two arguments (0x20, 3), ret 8) and its eax is stored at this+0x6c (the exe jumps past the
// move of p). Then the object at this+0x6c gets its vslot 0x98(0, bits(a), 0) (thiscall, the callee's own ret); the returned
// pointer r gets r[-4] = c, r[0] = 1, r[4] = b, and r is the function's result. GUESS: the names and slot numbers.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_41e290[], ext_4ccad0[];
typedef u32(*NewFn)(u32 size);
typedef u32(THISCALL *LinkSortCtor)(void *self, u32 a, u32 b);

u32 THISCALL GUESS_461570(u8 *self, float a, u32 b, u32 c) {
  if (AT(u32, self, 0x6c) == 0) {
    u32 p = ((NewFn)(void *)ext_41e290)(0x2cu);
    u32 r = 0;
    if (p) r = ((LinkSortCtor)(void *)ext_4ccad0)((void *)p, 0x20u, 3u);
    AT(u32, self, 0x6c) = r;
  }
  u32 obj = AT(u32, self, 0x6c);
  u32 abits = __builtin_bit_cast(u32, a);
  u32 r = vcall<u32>((void *)obj, 0x98, (u32)0, abits, (u32)0);
  AT(u32, r, 0xfffffffcu) = c;
  AT(u32, r, 0) = 1u;
  AT(u32, r, 4) = b;
  return r;
}
PCREG(461570, GUESS_461570);
