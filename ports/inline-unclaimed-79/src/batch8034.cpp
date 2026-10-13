#include "ff.h"
// batch8034.cpp - residue 18 unported list (docs/20-unclaimed-79.md). Names GUESS (no GC name). Helpers stubbed in spec.

extern "C" void *STDCALL ext_6014a0(u32 size);     // stdcall allocator (ret 4; forwards to 0x41e290)

// 0x563d60 (GUESS): thiscall, no args. o = slot 0x84 of this; v = slot 0x2f0 of o. When the dword at this+0xf4 differs from v,
// stores v there and calls slot 0xc4 of this with 1.
static void THISCALL f_563d60(u8 *self) {
  u8 *o = vcall<u8 *>(self, 0x84);
  u32 v = vcall<u32>(o, 0x2f0);
  if (*(u32 *)(self + 0xf4) != v) {
    *(u32 *)(self + 0xf4) = v;
    vcall<void, u32>(self, 0xc4, 1u);
  }
}
PCREG(563d60, f_563d60);

// 0x4ffea0 (GUESS): stdcall (n, begin, end), ret 0xc. block = n ? 0x6014a0(4 * n) : 0. Copies (end - begin + 3) / 4 dwords from
// begin (none when begin > end); a destination address of 0 skips the store. Returns block.
static u32 STDCALL f_4ffea0(u32 n, u32 begin, u32 end) {
  u32 block = 0;
  if (n != 0) block = (u32)(unsigned long)ext_6014a0(n << 2);
  u32 cnt = begin > end ? 0u : (end - begin + 3u) >> 2;
  for (u32 i = 0; i < cnt; ++i) {
    u32 d = block + 4u * i;
    if (d != 0) *(u32 *)(unsigned long)d = *(u32 *)(unsigned long)(begin + 4u * i);
  }
  return block;
}
PCREG(4ffea0, f_4ffea0);
