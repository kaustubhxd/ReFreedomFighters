// batch37116.cpp - cascade s6 batch 37116: 0x5a8550.
#include "ff.h"

extern "C" void THISCALL ext_4de7a0(u8 *m);                          // resets a matrix-like block (plain ret)
extern "C" void THISCALL ext_4dc630(u8 *self, u32 flags, u32 inv);   // ret 8
extern "C" void *__attribute__((cdecl)) ext_41e290(u32 bytes);       // allocate

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))

static inline u8 *tabObj() { return *(u8 **)(*(u8 **)0x70039c + 0x9b); }
static u32 sat4(u32 n) {
  u64 b = (u64)n * 4;
  return (b >> 32) ? 0xffffffffu : (u32)b;
}

// 0x5a8550, thiscall(idA, idB, count) ret 0xc: this+0 = count, +4 / +8 = two arrays of `count` object pointers. The objects idA and idB resolve to (table slot 0x58) are asked
// (slot 0x1bc with the table object's field +0xadc, a zeroed 0x24-byte block, a zeroed 3-dword vector and four zeros) to make one instance each per entry; each instance gets 0x4dc630
// (flags 0x40000) on its +8 member and is then released through its slot 0x28.
static void THISCALL fn5a8550(u8 *self, u32 idA, u32 idB, u32 count) {
  D32(self, 0) = count;
  D32(self, 4) = (u32)ext_41e290(sat4(count));
  D32(self, 8) = (u32)ext_41e290(sat4(D32(self, 0)));
  u32 blk[9];
  ext_4de7a0((u8 *)blk);
  u32 vec[3] = {0, 0, 0};
  void *a = (void *)vcall<u32>(tabObj(), 0x58, idA);
  void *b = (void *)vcall<u32>(tabObj(), 0x58, idB);
  for (u32 i = 0; i < D32(self, 0); i++) {
    u32 r = vcall<u32>(a, 0x1bc, D32(tabObj(), 0xadc), (u32)blk, (u32)vec, 0u, 0u, 0u, 0u);
    ((u32 *)D32(self, 4))[i] = r;
    ext_4dc630(*(u8 **)(r + 8), 0x40000, 0);
    vcall<void>((void *)((u32 *)D32(self, 4))[i], 0x28);
    u32 r2 = vcall<u32>(b, 0x1bc, D32(tabObj(), 0xadc), (u32)blk, (u32)vec, 0u, 0u, 0u, 0u);
    ((u32 *)D32(self, 8))[i] = r2;
    ext_4dc630(*(u8 **)(r2 + 8), 0x40000, 0);
    vcall<void>((void *)((u32 *)D32(self, 8))[i], 0x28);
  }
}
PCREG(5a8550, fn5a8550);
